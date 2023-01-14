//
// Created by roi on 12/31/22.
//

#include "ClientInit.h"

/**
 * ClientInit Constructor
 */
ClientInit::ClientInit() = default;

/**
 * ClientInit Constructor with arguments [ip,port]
 * @param arguments string -> [ip,port]
 * @param size is the size of the array of arguments
 */
ClientInit::ClientInit(char **arguments, int size) {
    this->arguments = arguments;
    this->size = size;
}

/**
 * Getter for port
 * @return string port
 */
string ClientInit::getPort() {
    return this->arguments[2];
}

/**
 * Getter for IP
 * @return string IP
 */
string ClientInit::getIP() {
    return this->arguments[1];
}

/**
 * check validity of arguments to be of type -> [ip,port]
 * so that IP is of type IPV4 and port has a valid range
 * @return true if arguments are valid, otherwise false
 */
bool ClientInit::argCheck() {
    // checking for valid number of arguments
    if (size != 3) {
        cout << "Too many arguments" << endl;
        return false;
    }
    // checking port validity
    for (int i = 0; i < getPort().length(); i++) {
        if (!isdigit(getPort()[i])) {
            cout << "invalid port" << endl;
            return false;
        }
    }
    int portNum = stoi(getPort());
    if (!(0 < portNum && portNum < 65535)) {
        cout << "invalid port" << endl;
        return false;
    }
    // checking ipv4 validity
    stringstream ss(getIP());
    int n[4];
    for (int i = 0; i < 4; ++i) {
        if (!(ss >> n[i]) || n[i] < 0 || n[i] > 255) {
            cout << "invalid IP" << endl;
            return false;
        }
        if (i < 3 && ss.get() != '.') {
            cout << "invalid IP" << endl;
            return false;
        }
    }
    if (!ss.eof()) {
        cout << "invalid IP" << endl;
        return false;
    }
    return true;
}