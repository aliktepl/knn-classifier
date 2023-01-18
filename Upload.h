//
// Created by alik on 1/18/23.
//

#ifndef AX1_EX4_UPLOAD_H
#define AX1_EX4_UPLOAD_H

#include "Command.h"

class Upload: public Command {
public:
    Upload();
    void execute() override;
};


#endif //AX1_EX4_UPLOAD_H
