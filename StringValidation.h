//
// Created by roi on 1/3/23.
//

#ifndef AP1_EX3_STRINGVALIDATION_H
#define AP1_EX3_STRINGVALIDATION_H

#include <cstring>
#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

/**
 * This class initialises vector, distance and k parameters for any string input
 * and checks these parameters validity
 */
class StringValidation {
private:
    vector<double> v; // vector part in v
    string distance; // distance part in input
    double k = 0; // k part in input
    bool invalid = false; // bool field for validation
public:
    StringValidation();

    explicit StringValidation(string input);

    vector<double> getVector();

    void setVector(vector<double> v);

    string getDistance();

    void setDistance(string distance);

    double getK();

    void setK(double k);

    bool getInvalid();

    void setInvalid(bool passedBool);

    bool checkValidation();
};


#endif //AP1_EX3_STRINGVALIDATION_H
