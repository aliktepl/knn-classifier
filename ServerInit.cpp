//
// Created by alik on 12/31/22.
//

#include "ServerInit.h"

using namespace std;
/**
 * Destructor
 */
ServerInit::~ServerInit() = default;
/**
 * Initializes the command line argument to.
 * @param arguments command line arguments
 * @param size amount of arguments
 */
ServerInit::ServerInit(char **arguments, int size) {
    this->arguments = arguments;
    this->size = size;
}
/**
 * Check the validity of the arguments.
 * @return true if the arguments are in a valid format.
 */
bool ServerInit::checkArg() {
    if (this->size != 2) {
        return false;
    }
    if(!isInt(arguments[1])){
        return false;
    }
    int port = stoi(arguments[1]);
    if (port < 0 || port > 65535) {
        return false;
    }
    return true;
}

int ServerInit::getPort() {
    // use check method first!
    return stoi(arguments[1]);
}
