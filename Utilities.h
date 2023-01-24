//
// Created by roi on 1/19/23.
//

#ifndef AX1_EX4_UTILITIES_H
#define AX1_EX4_UTILITIES_H
#include "string"
#include "vector"
#include "sstream"
#include "Classified.h"
#include "fstream"

using namespace std;
bool isInt(string str);
bool isNumeric(string str);
bool isContained(vector<int> numVector, int num);
bool checkMetric(const string& type);
bool checkClassifiedVec(const string& elements);;
string readFile(string path);
void writeFile(string toWrite, string path);

#endif //AX1_EX4_UTILITIES_H