//
// Created by alikt on 05/12/2022.
//

#ifndef AP1_EX2_KNEARESTNEIGHBORS_H
#define AP1_EX2_KNEARESTNEIGHBORS_H

#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include "Distances.h"
#include "Classified.h"

using namespace std;

class kNearestNeighbors {
private:
    int k;
    vector<Classified> classified;
    vector<double> unclassified;
public:
    kNearestNeighbors(vector<Classified> classified1, vector<double> unclassified, int k);
    vector<pair<Classified, double>> calculateDistances(const string& distance, int p);
    string mapDistances(vector<pair<Classified, double>> pairs) const;
    static bool compare(pair<Classified, double>& a, pair<Classified,double>& b);
};


#endif //AP1_EX2_KNEARESTNEIGHBORS_H
