//
// Created by roi on 1/23/23.
//

#include "ThreadWrapper.h"

void executeThread(int client_sock){
    SocketIO sio(client_sock);
    CLI cli(&sio);
    cli.start(client_sock);
}