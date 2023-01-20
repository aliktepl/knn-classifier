//
// Created by roi on 1/19/23.
//

#ifndef AX1_EX4_UTILITIES_H
#define AX1_EX4_UTILITIES_H
#include "string"
#include "vector"
#include "sstream"
#include "Classified.h"

using namespace std;
bool isInt(string str);
bool isContained(vector<int> numVector, int num);
bool checkMetric(const string& type);
bool checkClassifiedVec(const string& elements);
bool checkKParam();

#endif //AX1_EX4_UTILITIES_H