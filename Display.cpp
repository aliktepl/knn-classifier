//
// Created by alik on 1/18/23.
//

#include "Display.h"

Display::Display(DefaultIO *dio) : Command(dio) {
    this->description = "4. display results";
}

void Display::execute(Configuration *config) {
    if (!config->getExecutes()[0]){
        dio->write("please upload data");
    }
    else if(!config->getExecutes()[2]) {
        dio->write("please classify the data");
    }
    for (int i = 0; i < config->getClassifications().size(); i++) {
        dio->write(to_string(i) + "    " + config->getClassifications()[i]);
    }
    dio->write("Done");
}

