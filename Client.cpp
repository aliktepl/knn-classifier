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
#include "Utilities.h"
#include "thread"

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
        // receive message
        char buffer[4096];
        int expected_data_len = sizeof(buffer);
        int read_bytes = recv(sock, buffer, expected_data_len, 0);
        if (read_bytes < 0) {
            close(sock);
            // error
        }
        getline(cin, str);
        unsigned long data_len = str.length();
        int sent_bytes;
        string path, bufferStr;
        thread t;
        switch (stoi(str)) {
            case 1:
                // sends "1" to server to execute upload
                sent_bytes = send(sock, str.c_str(), data_len, 0);
                if (sent_bytes < 0) {
                    close(sock);
                    break;
                    // error
                }
                for(int i = 0; i < 2; i++){
                    // receives request to upload csv file
                    read_bytes = recv(sock, buffer, expected_data_len, 0);
                    if (read_bytes < 0) {
                        close(sock);
                        // error
                    }
                    cout << buffer << endl;
                    // read data from file and upload to server
                    cin >> path;
                    str = readFile(path);
                    data_len = str.length();
                    sent_bytes = send(sock, str.c_str(), data_len, 0);
                    if (sent_bytes < 0) {
                        close(sock);
                        break;
                        // error
                    }
                    // receives "Upload complete message"
                    read_bytes = recv(sock, buffer, expected_data_len, 0);
                    if (read_bytes < 0) {
                        close(sock);
                        // error
                    }
                }
                break;

            case 2:
                // send option "2" to server
                sent_bytes = send(sock, str.c_str(), data_len, 0);
                if (sent_bytes < 0) {
                    close(sock);
                    break;
                    // error
                }
                // receive current configuration of K and metric
                read_bytes = recv(sock, buffer, expected_data_len, 0);
                if (read_bytes < 0) {
                    close(sock);
                    // error
                }
                // send new configuration
                cin >> str;
                sent_bytes = send(sock, str.c_str(), data_len, 0);
                if (sent_bytes < 0) {
                    close(sock);
                    break;
                    // error
                }
                break;

            case 5:
                // send option "5" to server
                sent_bytes = send(sock, str.c_str(), data_len, 0);
                if (sent_bytes < 0) {
                    close(sock);
                    break;
                    // error
                }
                // receive current configuration of K and metric
                read_bytes = recv(sock, buffer, expected_data_len, 0);
                if (read_bytes < 0) {
                    close(sock);
                    // error
                }
                bufferStr = string(buffer, strlen(buffer));
                cin >> path;
                t = thread(writeFile, bufferStr, path);
                t.detach();
                break;

            case 8:
                // if message is "8" then close socket for current client
                close(sock);
                return 0;

            default:
                // send option x from menu
                sent_bytes = send(sock, str.c_str(), data_len, 0);
                if (sent_bytes < 0) {
                    close(sock);
                    break;
                    // error
                }
                // receive operation x execution output from server
                read_bytes = recv(sock, buffer, expected_data_len, 0);
                if (read_bytes < 0) {
                    close(sock);
                    // error
                }
                break;

        }
        // clearing the buffer for next message
        memset(buffer, 0, sizeof(buffer));
        }
}