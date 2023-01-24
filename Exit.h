//
// Created by roi on 1/18/23.
//

#ifndef AX1_EX4_EXIT_H
#define AX1_EX4_EXIT_H

#include "Command.h"
#include "iostream"

using namespace std;

class Exit : public Command {
public:
    explicit Exit(DefaultIO *dio);
    void execute(Configuration *config) override;
};


#endif //AX1_EX4_EXIT_H
