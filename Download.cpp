//
// Created by alik on 1/18/23.
//

#include "Download.h"

Download::Download(DefaultIO *dio) : Command(dio) {
    this->description = "5. download results";
}


void Download::execute(Configuration *config) {
    if (!config->getExecutes()[0]){
        dio->write("please upload data");
    }
    else if(!config->getExecutes()[2]) {
        dio->write("please classify the data");
    }
    string results;
    for (int i = 0; i < config->getClassifications().size(); i++) {
        results.append(to_string(i) + "    " + config->getClassifications()[i] + '\n');
    }
    dio->write(results);
}

