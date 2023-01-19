//
// Created by alik on 1/18/23.
//

#ifndef AX1_EX4_COMMAND_H
#define AX1_EX4_COMMAND_H

#include <string>
#include "DefaultIO.h"
#include "Configuration.h"

using namespace std;


class Command {
protected:
    Configuration config;
    string description;
    DefaultIO *dio;
public:
    Command(DefaultIO *dio);
    string getDescription();
    Configuration getConfig();
    virtual void execute() = 0;
};



#endif //AX1_EX4_COMMAND_H
