//
// Created by alik on 1/18/23.
//

#include "Display.h"

Display::Display(DefaultIO *dio) : Command(dio) {
    this->description = "4. display results";
}
/**
 * Sends the classified vectors to the client for printing.
 * @param config
 */
void Display::execute(Configuration *config) {
    if (!config->getExecutes()[0]){
        dio->write("please upload data");
        return;
    }
    else if(!config->getExecutes()[2]) {
        dio->write("please classify the data");
        return;
    }
    string results;
    for (unsigned long i = 0; i < config->getClassifications().size(); i++) {
        results.append(to_string(i+1) + "    " + config->getClassifications()[i]+'\n');
    }
    results.append("Done");
    std::this_thread::sleep_for(std::chrono::milliseconds(1));
    dio->write(results);
}

