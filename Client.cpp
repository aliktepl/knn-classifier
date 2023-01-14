//
// Created by roi on 12/31/22.
//
#include <iostream>
#include <sys/socket.h>
#include <cstdio>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <cstring>
#include "ClientInit.h"
#include "StringValidation.h"

using namespace std;

/**
 * this part of the code runs the client end of the code.
 * it connects to the server given ip,port input from command line
 * Then sends in an endless loop the message -> [vector,distance,k] .
 * it then receives from the serves the classification of the vector
 * that was sent given a distance and a k.
 * @param argc count of arguments
 * @param argv string array of [ip,port]
 * @return
 */
int main(int argc, char **argv) {
    // validate ip, port with clientInit class
    ClientInit clientInit(argv, argc);
    if (!clientInit.argCheck()) {
        cout << "Invalid input" << endl;
        return 0;
    }
    // create TCP socket
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("error creating socket");
    }
    // initialise sin struct -> TCP,port,ip of client to send to server
    struct sockaddr_in sin;
    memset(&sin, 0, sizeof(sin));
    sin.sin_family = AF_INET;
    sin.sin_addr.s_addr = inet_addr(clientInit.getIP().c_str());
    sin.sin_port = htons(stoi(clientInit.getPort()));
    // connect to server with sin of client
    if (connect(sock, (struct sockaddr *) &sin, sizeof(sin)) < 0) {
        perror("error connecting to server");
    }
    /**
     * run in an endless loop of sending message -> [vector,distance,k]
     * and receiving server message -> classification
     * until terminated by the message "-1"
     */
    string str;
    while (true) {
        getline(cin, str);
        int data_len = str.length();
        if (str != "-1") {
            // initialise vector,distance,k from user input and check their validity
            StringValidation stringValidation(str);
            if (!stringValidation.checkValidation()) {
                cout << "Invalid input" << endl;
                continue;
            }
        }
        // send message -> [vector, distance, k]
        int sent_bytes = send(sock, str.c_str(), data_len, 0);
        // if message is "-1" then close socket for client
        if (str == "-1") {
            close(sock);
            return 0;
        }
        if (sent_bytes < 0) {
            close(sock);
            break;
            // error
        }
        // receive message -> classification
        char buffer[4096];
        int expected_data_len = sizeof(buffer);
        int read_bytes = recv(sock, buffer, expected_data_len, 0);
        // if message -> "-1" then close socket
        if (read_bytes == 1 && buffer[0] == -1) {
            close(sock);
            // connection is closed
        } else if (read_bytes < 0) {
            close(sock);
            // error
        } else {
            cout << buffer << endl;
        }
        // clearing the buffer for next message
        memset(buffer, 0, sizeof(buffer));
    }
    close(sock);
    return 0;
}
