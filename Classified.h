//
// Created by alikt on 05/12/2022.
//

#ifndef AP1_EX2_CLASSIFIED_H
#define AP1_EX2_CLASSIFIED_H

#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Classified {
private:
    string category;
    vector<double> vect;

public:
    explicit Classified(std::vector<double> vector1, string category);
    std::vector<double> getVector();
    string getCategory() const;
    bool distValidation(unsigned long long vSize);
};


#endif //AP1_EX2_CLASSIFIED_H
