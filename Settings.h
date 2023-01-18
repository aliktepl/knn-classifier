//
// Created by alik on 1/18/23.
//

#ifndef AX1_EX4_SETTINGS_H
#define AX1_EX4_SETTINGS_H

#include "Command.h"

class Settings: public Command {
    Settings();
    void execute() override;
};


#endif //AX1_EX4_SETTINGS_H
