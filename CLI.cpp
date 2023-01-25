//
// Created by roi on 1/18/23.
//

#include "CLI.h"
#include <chrono>
#include <thread>

/**
 * Constructor takes default io and fills command vectors with current commands.
 * @param dio is the default io
 */
CLI::CLI(DefaultIO *dio) {
    this->dio = dio;
    Upload *upload = new Upload(getDio());
    this->commands.push_back(upload);
    Settings *settings = new Settings(getDio());
    this->commands.push_back(settings);
    Classify *classify = new Classify(getDio());
    this->commands.push_back(classify);
    Display *display = new Display(getDio());
    this->commands.push_back(display);
    Download *download = new Download(getDio());
    this->commands.push_back(download);
    Exit *exit = new Exit(getDio());
    this->commands.push_back(exit);
}

vector<Command *> CLI::getCommands() {
    return this->commands;
}

DefaultIO *CLI::getDio() {
    return this->dio;
}

/**
 * The start method initiates the interaction between the client and server,
 * and is responsible for the flow of the interaction between client and server.
 * When the connection ends and the user decides to exit it ends.
 */
void CLI::start(int id) {
    string menu;
    menu.append("Welcome to the KNN Classifier Server. Please choose an option:\n");
    for (auto command: getCommands()) {
        menu.append(command->getDescription());
        menu.append("\n");
    }
    string option;
    Configuration config = Configuration();
    while (true) {
        getDio()->write(menu);
        option = getDio()->read();
        if (!isInt(option)) {
            continue;
        }
        int optionNum = stoi(option);
        vector<int> validOptions = {1, 2, 3, 4, 5, 8};
        if (!isContained(validOptions, optionNum)) {
            continue;
        }
        if (optionNum == 8) {
            getCommands().at(optionNum - 3)->execute(&config);
            break;
        }
        Command* currCommand = getCommands().at(optionNum - 1);
        currCommand->execute(&config);
    }
}