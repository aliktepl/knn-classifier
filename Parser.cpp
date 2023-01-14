//
// Created by royva on 13/12/2022.
//

#include "Parser.h"

/**
 * constructor for Parser class.
 * @param delim is the delimited of the string
 * @param toParse is the string to parse
 */
Parser::Parser(char delim, string toParse) {
    this->delim = delim;
    this->toParse = toParse;
}

/**
 * Setter for delimiter
 * @param delim0 is the delimiter
 */
void Parser::setDelim(char delim0) {
    this->delim = delim0;
}

/**
 * Setter for string to parse
 * @param toParse0 string
 */
void Parser::setToParse(string toParse0) {
    this->toParse = std::move(toParse0);

}

/**
 * Getter for delimiter
 * @return char delimiter
 */
char Parser::getDelim() {
    return this->delim;
}

/**
 * Getter for string to parse
 * @return string
 */
string Parser::getToParse() {
    return this->toParse;
}

/**
 * iterate string to parse and count amount of delimiters
 * @return count of delimiter
 */
int Parser::checkParse() {
    int parserCount = 0;
    for (int i = 0; i < getToParse().length(); i++) {
        if (getToParse()[i] == getDelim()) { parserCount++; }
    }
    return parserCount;
}
/**
 * parse string by delimiter and return exponent calculation
 * @return double exponent calculation
 */
double Parser::parse() {
    stringstream es(getToParse());
    vector<string> tokens;
    string token;
    char *end;
    while (getline(es, token, getDelim())) {
        tokens.push_back(token);
    }
    double exponent = pow(10, strtod(tokens[1].c_str(), &end));
    double base = strtod(tokens[0].c_str(), &end);
    return base * exponent;
}
/**
 * Default constructor for parser
 */
Parser::Parser() = default;
