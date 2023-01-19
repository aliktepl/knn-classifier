//
// Created by alik on 1/18/23.
//

#include "Display.h"

Display::Display(DefaultIO *dio) : Command(dio) {
    this->description = "4. display results";
}

void Display::execute() {

    dio->write("Done");
}

