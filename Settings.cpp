//
// Created by alik on 1/18/23.
//

#include "Settings.h"
#include "sstream"
#include "Utilities.h"

Settings::Settings(DefaultIO *dio) : Command(dio) {
    this->description = "2. algorithm settings";
}


void Settings::execute(Configuration *config) {
    dio->write("The current KKN parameters are: K = " +
                to_string(config->getK()) + ", distance metric = " + config->getMetric());
    // K Metric
    string settings_input = dio->read();
    stringstream ss(settings_input);
    string word;
    while (ss >> word) {
        if (isInt(word)) {
            config->setK(stoi(word));
        } else {
            config->setMetric(word);
        }
    }
    config->setExecute(true, 1);
}
