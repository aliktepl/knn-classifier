//
// Created by roi on 1/18/23.
//

#include "Exit.h"

Exit::Exit(DefaultIO *dio) : Command(dio) {
    this->description = "8. exit";
}

/**
 * Closes the necessary connections and exits the client. The server then waits for new connections.
 * @param config
 */
void Exit::execute(Configuration *config) {
    dio->exit();
}
