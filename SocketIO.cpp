//
// Created by alik on 1/21/23.
//

#include "SocketIO.h"

SocketIO::SocketIO(int client_sock) {
    this->client_sock = client_sock;
}

string SocketIO::read() {
    char buffer[4096];
    memset(buffer, 0, sizeof(buffer));
    int expected_data_len = sizeof(buffer);
    int read_bytes = recv(client_sock, buffer, expected_data_len, 0);
    //convert the buffer to a string
    string buffer_str(buffer, read_bytes);
    return buffer_str;
}

void SocketIO::write(string data) {
    int sent_bytes = send(client_sock, data.c_str(), data.size(), 0);
    if (sent_bytes < 0) {
        return;
    }
}

void SocketIO::exit() const {
    close(this->client_sock);
}
