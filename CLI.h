//
// Created by roi on 1/18/23.
//

#ifndef AX1_EX4_CLI_H
#define AX1_EX4_CLI_H
#include "DefaultIO.h"
#include "Command.h"
#include <vector>

using namespace std;

class CLI {
private:
    DefaultIO dio;
    vector<Command*> commands = {};
public:
    CLI(DefaultIO dio);
    void start();
};


#endif //AX1_EX4_CLI_H
