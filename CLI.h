//
// Created by roi on 1/18/23.
//

#ifndef AX1_EX4_CLI_H
#define AX1_EX4_CLI_H

#include "DefaultIO.h"
#include "Command.h"
#include "Upload.h"
#include "Settings.h"
#include "Classify.h"
#include "Display.h"
#include "Download.h"
#include "Exit.h"
#include "vector"
#include "Utilities.h"
#include "iostream"

using namespace std;

class CLI {
private:
    DefaultIO *dio;
    vector<Command *> commands = {};
public:
    CLI(DefaultIO *dio);

    void start(int id, bool *closeConnection);

    vector<Command *> getCommands();

    DefaultIO *getDio();
};


#endif //AX1_EX4_CLI_H
