//
// Created by alik on 1/18/23.
//

#include "Settings.h"

Settings::Settings(DefaultIO *dio) : Command(dio) {
    this->description = "2. algorithm settings";
}

/**
 * The client sends new K and metric for the classifier to use, and they are added to the configuration, the default
 * K and metric are K = 5, metric = AUC.
 * @param config
 */
void Settings::execute(Configuration *config) {
    dio->write("The current KKN parameters are: K = " +
                to_string(config->getK()) + ", distance metric = " + config->getMetric());
    // K Metric
    string settings_input = dio->read();
    if(settings_input == "\n"){
        dio->write("ret");
        return;
    }
    stringstream ss(settings_input);
    string word, error, metric;
    int k = 0;
    while (getline(ss, word, ' ')) {
        //check if k is valid
        if (isInt(word)) {
            int num = stoi(word);
            if (0 < num && num <= config->getTrainVectors().size()) {
                k = num;
            } else {
                if(error.empty()){
                    error.append("Invalid value for K");
                } else {
                    error.append("\nInvalid value for K");
                }
            }
        }
        //check if the metric is valid
        else {
            if(!checkMetric(word)) {
                if(error.empty()){
                    error.append("Invalid value for metric");
                } else {
                    error.append("\nInvalid value for metric");
                }
            } else {
                metric = word;
            }
        }
    }
    if (error.empty() && !(k == 0 && metric.empty())) {
        config->setK(k);
        config->setMetric(metric);
        config->setExecute(true, 1);
        dio->write("ret");
    } else {
        dio->write(error);
    }
}
