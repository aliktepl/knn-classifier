//
// Created by alikt on 05/12/2022.
//

#include "Classified.h"

/**
 * A class that defines a vector and a its category
 * @param vector1 the numeric vector
 * @param category1 the category of the vector
 */
Classified::Classified(std::vector<double> vector1, string category1) {
    this->category = std::move(category1);
    this->vect = std::move(vector1);
}

/**
 * gets the vector
 * @return a vector
 */
std::vector<double> Classified::getVector() {
    return this->vect;
}
/**
 * Get th category
 * @return the category
 */
string Classified::getCategory() const {
    return this->category;
}
/**
 * Check the validity of the vector's length
 * @param vSize vector length
 * @return
 */
bool Classified::distValidation(unsigned long long vSize) {
    if (getVector().size() != vSize) {
        return false;
    } else {
        return true;
    }
}
