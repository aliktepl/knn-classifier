//
// Created by alik on 1/18/23.
//

#ifndef AX1_EX4_DEFAULTIO_H
#define AX1_EX4_DEFAULTIO_H

#include "string"

using namespace std;


class DefaultIO {
public:
    virtual string read() = 0;
    virtual void write(string data) = 0;
    virtual void exit() const = 0;

};



#endif //AX1_EX4_DEFAULTIO_H
