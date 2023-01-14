//
// Created by roi on 12/31/22.
//

#ifndef AP1_EX3_CLIENTINIT_H
#define AP1_EX3_CLIENTINIT_H

#include <iostream>
#include <cstring>
#include <sstream>
#include <ostream>
#include <vector>

using namespace std;
/**
 * This class initialises ip, port arguments and check for their validity
 */
class ClientInit {
private:
    char **arguments{};
    int size{};
public:
    ClientInit();

    ClientInit(char **arguments, int size);

    string getPort();

    string getIP();

    bool argCheck();
};


#endif //AP1_EX3_CLIENTINIT_H
