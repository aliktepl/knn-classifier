//
// Created by alik on 1/18/23.
//

#include "Settings.h"

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
    string error;
    int k;
    string metric;
    while (ss >> word) {
        if (isInt(word)) {
            if (0 < stoi(word) && config->getTrainVectors().size() <= k) {
                k = (stoi(word));
            } else {
                error.append("Invalid value for K\n");
            }
        }
        else {
            if(!checkMetric(word)) {
                error.append("Invalid value for metric\n");
            } else {
                metric = word;
            }
        }
    }
    if (error.empty()) {
        config->setK(k);
        config->setMetric(metric);
        config->setExecute(true, 1);
    } else {
        dio->write(error);
    }
}
