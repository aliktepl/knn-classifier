//
// Created by alik on 1/18/23.
//

#include <iostream>
#include "StandardIO.h"


/**
 * Reads input from the console
 * @return
 */
string StandardIO::read() {
    string input;
    cin >> input;
    return input;
}

/**
 * Writes the output to the console.
 * @param output
 */
void StandardIO::write(string output) {
    cout << output << endl;
}

void StandardIO::exit() const {

}

StandardIO::StandardIO() = default;
