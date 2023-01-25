//
// Created by alik on 1/18/23.
//

#include "Command.h"
/**
 * Virtual class that defines a command, a design pattern that can execute different operations.
 */
Command::Command(DefaultIO *dio) {
    this->dio = dio;
}

/**
 * gets the description of the current command.
 * @return the description
 */
string Command::getDescription() {
    return this->description;
}
