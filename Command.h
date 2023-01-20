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
    string description;
    DefaultIO *dio;
public:
    explicit Command(DefaultIO *dio);
    string getDescription();
    virtual void execute(Configuration *config) = 0;
};



#endif //AX1_EX4_COMMAND_H
