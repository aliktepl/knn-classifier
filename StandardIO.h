//
// Created by alik on 1/18/23.
//

#ifndef AX1_EX4_STANDARDIO_H
#define AX1_EX4_STANDARDIO_H

#include "DefaultIO.h"

class StandardIO : public DefaultIO {
public:
    string read() override;
    void write(string data) override;
    StandardIO();
};


#endif //AX1_EX4_STANDARDIO_H
