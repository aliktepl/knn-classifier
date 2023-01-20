//
// Created by royva on 06/12/2022.
//

#ifndef AP1_EX2_FILEREADER_H
#define AP1_EX2_FILEREADER_H

#include <fstream>
#include <ostream>
#include <cstring>
#include <vector>
#include <sstream>
#include <cmath>
#include "Classified.h"
#include "iostream"
#include "Parser.h"

using namespace std;

class FileReader {
private:
    char *path;
    vector<Classified> train_vector;
    vector<vector<double>> test_vector;
    unsigned long long size = 0;
public:
    explicit FileReader(char *path);

    ~FileReader();

    bool feedTrainVector();

    bool feedTestVector();

    vector<Classified> getTrainVector();

    vector<vector<double>> getTestVector();

    unsigned long long getSize() const;
};


#endif //AP1_EX2_FILEREADER_H
