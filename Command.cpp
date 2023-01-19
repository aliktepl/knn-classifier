//
// Created by alik on 1/18/23.
//

#include "Command.h"

Command::Command(DefaultIO *dio) {
    this->dio = dio;
}

string Command::getDescription() {
    return this->description;
}
