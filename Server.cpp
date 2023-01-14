//
// Created by royva on 05/12/2022.
//

#include "FileReader.h"
#include "kNearestNeighbors.h"
#include "StringValidation.h"
#include "ServerInit.h"
#include <iostream>
#include <sys/socket.h>
#include <cstdio>
#include <netinet/in.h>
#include <unistd.h>
#include <cstring>

using namespace std;

/**
 * main class that gets arguments from user and runs the program.
 * @param argc is the amount of arguments
 * @param argv is the argument vector
 * @return '0' if the program was executed correctly
 */
int main(int argc, char **argv) {
    ServerInit serverInit(argv, argc);
    // check if arguments are valid
    if (!serverInit.checkArg()) {
        cout << "Invalid input!" << endl;
        return 0;
    }
    // pass file path to file reader and instantiate it
    FileReader fileReader = FileReader(serverInit.filePath());
    // feed 'classified' vector file contents and return true if done successfully
    if (!fileReader.feedVector()) {
        return 0;
    }
    vector<Classified> classifiedVectors = fileReader.getVector();
    //default p value for minkowski distance
    int p = 2;
    //get the port
    const int server_port = serverInit.getPort();
    //open the socket
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("error creating socket");
    }
    struct sockaddr_in sin;
    memset(&sin, 0, sizeof(sin));
    sin.sin_family = AF_INET;
    sin.sin_addr.s_addr = INADDR_ANY;
    sin.sin_port = htons(server_port);
    //bind the socket to the port
    if (bind(sock, (struct sockaddr *) &sin, sizeof(sin)) < 0) {
        perror("error binding socket");
    }
    if (listen(sock, 5) < 0) {
        perror("error listening to a socket");
    }
    struct sockaddr_in client_sin;
    unsigned int addr_len = sizeof(client_sin);
    //start accepting incoming connections
    while (true) {
        //accept a client connection
        int client_sock = accept(sock, (struct sockaddr *) &client_sin, &addr_len);
        if (client_sock < 0) {
            perror("error accepting client");
        }
        string cat;
        while (true) {
            char buffer[4096];
            int expected_data_len = sizeof(buffer);
            //receive a vectore, distance and k from the client
            int read_bytes = recv(client_sock, buffer, expected_data_len, 0);
            //convert the buffer to a string
            string buffer_str(buffer, read_bytes);
            //if there was a problem receiving the message tell the client
            if (read_bytes == 0) {
                cat = "invalid input";
            } else if (read_bytes < 0) {
                cat = "invalid input";
            } else {
                //if the client sent -1 wait for new connections
                if(buffer_str == "-1") {
                    break;
                }
                //validate the string
                StringValidation valid(buffer_str);
                if (!valid.checkValidation()) {
                    cat = "invalid input";
                } else {
                    vector<double> input = valid.getVector();
                    string distance = valid.getDistance();
                    int k = valid.getK();
                    //if the vector or k don't fit the file send error.
                    if(k > classifiedVectors.size() || input.size() != fileReader.getSize()) {
                        cat = "invalid input";
                    } else {
                        //calculate the category
                        kNearestNeighbors knn(classifiedVectors, input, k);
                        cat = knn.mapDistances(knn.calculateDistances(distance, p));
                    }
                }
            }
            //send the category or the error message to the client.
            int sent_bytes = send(client_sock, cat.c_str(), cat.size(), 0);
            memset(buffer, 0, sizeof(buffer));
            if (sent_bytes < 0) {
                break;
            }
        }
    }
    close(sock);
    return 0;
}