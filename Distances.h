//
// Created by alikt on 05/12/2022.
//

#ifndef AP1_EX2_DISTANCES_H
#define AP1_EX2_DISTANCES_H

#include <string>
#include <vector>
#include <cmath>
using namespace std;


class Distances {
public:
    explicit Distances();
    static double minkowski(const vector<double>& vector1, const vector<double>& vector2, int p);
    static  double euclidean(const vector<double>& vector1, const vector<double>& vector2);
    static double canberra(const vector<double>& vector1, const vector<double>& vector2);
    static double chebyshev(const vector<double>& vector1, const vector<double>& vector2);
    static  vector<double> fillDistances(vector<double> v1,vector<double> v2);
    static  vector<double> fillSums(vector<double> v1,vector<double> v2);
    static  int precision(double number);

};


#endif //AP1_EX2_DISTANCES_H
