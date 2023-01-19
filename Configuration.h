//
// Created by roi on 1/19/23.
//

#ifndef AX1_EX4_CONFIGURATION_H
#define AX1_EX4_CONFIGURATION_H
#include "string"
using namespace std;
class Configuration {
private:
    string trainPath;
    string testPath;
    string metric;
    int k;
public:
    Configuration();
    string getTrainPath();
    string getTestPath();
    string getMetric();
    int getK();
    void setTrainPath(string path);
    void setTestPath(string path);
    void setMetric(string metric);
    void setK(int k);
};


#endif //AX1_EX4_CONFIGURATION_H
