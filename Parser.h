//
// Created by royva on 13/12/2022.
//

#ifndef AP1_EX2_PARSER_H
#define AP1_EX2_PARSER_H

#include <cstring>
#include <iostream>
#include <vector>
#include <sstream>
#include <cmath>

using namespace std;

class Parser {
private:
    char delim{};
    string toParse;
public:
    Parser();

    Parser(char delim, string toParse);

    void setDelim(char delim);

    void setToParse(string toParse);

    char getDelim();

    string getToParse();

    int checkParse();

    double parse();

};


#endif //AP1_EX2_PARSER_H
