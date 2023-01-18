//
// Created by alik on 1/18/23.
//

#ifndef AX1_EX4_DOWNLOAD_H
#define AX1_EX4_DOWNLOAD_H

#include "Command.h"


class Download: public Command {
    Download();
    void execute() override;
};


#endif //AX1_EX4_DOWNLOAD_H
