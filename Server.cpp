//
// Created by royva on 05/12/2022.
//

#include "kNearestNeighbors.h"
#include "ServerInit.h"
#include "CLI.h"
#include "SocketIO.h"
#include "ThreadWrapper.h"
#include <iostream>
#include <sys/socket.h>
#include <cstdio>
#include <netinet/in.h>
#include <unistd.h>
#include <cstring>
#include <thread>

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
//        SocketIO stdio = SocketIO(client_sock);
//        CLI clientCLI(&stdio);
        bool closeConnection = false;
        bool* ptrCloseConnection = &closeConnection;
        thread t(executeThread, client_sock, ptrCloseConnection);
        t.detach();
        if(*(ptrCloseConnection)){
            close(sock);
            t.join();
        }
    }
    return 0;
}