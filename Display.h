//
// Created by alik on 1/18/23.
//

#ifndef AX1_EX4_DISPLAY_H
#define AX1_EX4_DISPLAY_H

#include "Command.h"

class Display : public Command {
public:
    explicit Display(DefaultIO *dio);

    void execute(Configuration *config) override;
};


#endif //AX1_EX4_DISPLAY_H
