//
// Created by alik on 1/18/23.
//

#include <iostream>
#include "StandardIO.h"



string StandardIO::read() {
    string input;
    cin >> input;
    return input;
}

void StandardIO::write(string output) {
    cout << output << endl;
}

void StandardIO::exit() {

}

StandardIO::StandardIO() = default;
