//
// Created by alik on 1/18/23.
//

#include "Settings.h"

Settings::Settings(DefaultIO *dio) : Command(dio) {
    this->description = "2. algorithm settings";
}

void Settings::execute() {
    //default values
    int k = 5;
    string metric = "EUC";
    string settings_input = dio->read();
    dio->write("The current KKN parameters are: K = " + to_string(k) + ", distance metric = " + metric);
}
