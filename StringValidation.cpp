//
// Created by roi on 1/3/23.
//

#include "StringValidation.h"

/**
 * Default constructor for StringValidation.
 */
StringValidation::StringValidation() = default;

/**
 * Constructor gets string input and parses it to vector, distance and k
 * Then initialises these fields using setters .
 * @param input is the string input  from thus user.
 */
StringValidation::StringValidation(string input) {
    if (input.empty()) { return; }
    stringstream ss(input);
    string index;
    bool distFlag = false;
    vector<double> distVec;
    // parse vector part of the string and initialise it to distVec
    while (getline(ss, index, ' ')) {
        for (auto x: index) {
            if (!isdigit(x) && x != '.') { distFlag = true; }
        }
        if (distFlag) { break; }
        distVec.push_back(stod(index));
    }
    setVector(distVec);
    // parse distance part of string and initialise it to dist
    setDistance(index);
    // parse k part of string and initialise it to k
    getline(ss, index, ' ');
    for (auto x: index) {
        if (!isdigit(x)) { return; }
    }
    setK(stod(index));
    if (!ss.eof()) { setInvalid(true); }
}

/**
 * getter for vector input
 * @return v
 */
vector<double> StringValidation::getVector() {
    return this->v;
}

/**
 * Setter for input vector
 * @param vec is the vector to set to
 */
void StringValidation::setVector(vector<double> vec) {
    this->v = std::move(vec);
}

/**
 * Getter for distance input.
 * @return distance
 */
string StringValidation::getDistance() {
    return this->distance;
}

/**
 * Setter for distance
 * @param dist is the dist to set to
 */
void StringValidation::setDistance(string dist) {
    this->distance = std::move(dist);
}

/**
 * Getter for K input
 * @return k
 */
double StringValidation::getK() {
    return this->k;
}

/**
 * Setter for input K
 * @param passedK is the K to set to
 */
void StringValidation::setK(double passedK) {
    this->k = passedK;
}

/**
 * Check validation for parameters Vector, distance and K
 * @return false if one of the parameters is invalid, otherwise true
 */
bool StringValidation::checkValidation() {
    //validate input size
    if (getInvalid()) { return false; }
    // validate vector
    if (getVector().empty()) { return false; }
    // validate distance
    string dist = getDistance();
    if (!dist.empty() &&
        (strcmp(dist.c_str(), "AUC") != 0) && (strcmp(dist.c_str(), "MAN") != 0) &&
        (strcmp(dist.c_str(), "CHB") != 0) && (strcmp(dist.c_str(), "CAN") != 0) &&
        (strcmp(dist.c_str(), "MIN") != 0)) {
        return false;
    }
    // validate k
    if (getK() == 0) { return false; }
    return true;
}

/**
 * Getter for invalid boolean value
 * @return invalid boolean value
 */
bool StringValidation::getInvalid() {
    return this->invalid;
}

/**
 * Setter for boolean value
 * @param passedBool is the boolean value to set to
 */
void StringValidation::setInvalid(bool passedBool) {
    this->invalid = passedBool;
}
