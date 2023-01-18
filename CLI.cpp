//
// Created by roi on 1/18/23.
//

#include "CLI.h"
#include "Upload.h"
#include "Settings.h"
#include "Classify.h"
#include "Display.h"
#include "Download.h"
/**
 * Constructor takes default io and fills command vectors with current commands.
 * @param dio is the default io
 */
CLI::CLI(DefaultIO dio){
    this->dio = dio;
    Upload upload = Upload();
    this->commands.push_back(&upload);
    Settings settings = Settings();
    this->commands.push_back(&settings);
    Classify classify = Classify();
    this->commands.push_back(&classify);
    Display display = Display();
    this->commands.push_back(&display);
    Download download = Download();
    this->commands.push_back(&download);
}

void CLI::start() {

}