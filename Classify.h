//
// Created by alik on 1/18/23.
//

#ifndef AX1_EX4_CLASSIFY_H
#define AX1_EX4_CLASSIFY_H

#include "Command.h"

class Classify: public Command {
public:
    explicit Classify(DefaultIO *dio);
    void execute(Configuration *config) override;
};


#endif //AX1_EX4_CLASSIFY_H
