//
// Created by alik on 1/21/23.
//

#ifndef AX1_EX4_SOCKETIO_H
#define AX1_EX4_SOCKETIO_H

#include "DefaultIO.h"
#include <iostream>
#include <sys/socket.h>
#include <cstdio>
#include <netinet/in.h>
#include <unistd.h>
#include <cstring>

class SocketIO: public DefaultIO{
private:
    int client_sock;
public:
    explicit SocketIO(int client_sock);
    string read() override;
    void write(string data) override;
};


#endif //AX1_EX4_SOCKETIO_H
