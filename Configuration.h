//
// Created by roi on 1/19/23.
//

#ifndef AX1_EX4_CONFIGURATION_H
#define AX1_EX4_CONFIGURATION_H
#include "string"
#include "Classified.h"

using namespace std;

class Configuration {
private:
    string metric;
    int k;
    vector<Classified> trainVectors;
    vector<vector<double>> testVectors;
    vector<string> classifications;
    vector<bool> executes{false, false, false, false, false};
public:
    Configuration();
    ~Configuration();
    string getMetric();
    int getK() const;
    vector<Classified> getTrainVectors();
    vector<vector<double>> getTestVectors();
    void setTrainVectors(vector<Classified> vector);
    void setTestVectors(vector<vector<double>> vector);
    void setMetric(string metric);
    void setK(int k);
    void setExecute(bool option, int index);
    vector<bool> getExecutes();
    vector<string> getClassifications();
    void setClassifications(vector<string> strings);

};


#endif //AX1_EX4_CONFIGURATION_H
