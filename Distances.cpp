//
// Created by alikt on 05/12/2022.
//

#include "Distances.h"
/**
 * Default constructor.
 */
Distances::Distances() = default;

/**
 * Calculate the minkowski distance between 2 vectors.
 * @param v1 first vector
 * @param v2 second vector
 * @param p parameter in equation
 * @return minkowski distance between 2 vectors in double
 */
double Distances::minkowski(const vector<double> &v1, const vector<double> &v2, int p) {
    // get absolute distance of every index in vectors from func fill_distance and save to 'distances' vector
    vector<double> distances = fillDistances(v1, v2);
    double vectorSum = 0.0;
    // iterate over all indices of 'distances' vector and calculate minkowski distance
    for (double distance : distances) {
        vectorSum += pow(distance, p);
    }
    return pow(vectorSum, (double) (1.0 / p));
}

/**
 * this function calculates the euclidean distance of 2 vectors.
 * @param v1 first vector
 * @param v2 second vector
 * @return euclidean distance between the two vectors in double
 */
double Distances::euclidean(const vector<double>& v1, const vector<double>& v2) {
    if (v1.size() != v2.size()) { return 0; }
    double distance = 0;
    // iterate over all indices of vector and add calculation of indices to 'distance'
    for (int i = 0; i < v1.size(); i++) {
        distance += pow(v1[i] - v2[i], 2);
    }
    return sqrt(distance);
}

/**
 * The function calculates the Canberra distance between 2 vectors.
 * @param v1 the first vector.
 * @param v2 the second vector.
 * @return sum - The Canberra distance between 2 vectors.
 */
double Distances::canberra(const vector<double> &v1, const vector<double> &v2) {
    vector<double> distances = fillDistances(v1, v2);
    vector<double> sums = fillSums(v1, v2);
    double sum = 0;
    for (int i = 0; i < v1.size(); i++) {
        if(sums[i] == 0) {
            sum += 0;
        } else {
            sum += distances[i] / sums[i];
        }
    }
    return sum;
}

/**
 * This function calculates the Chebyshev distance between 2 vectors.
 * @param v1 first vector
 * @param v2 second vector
 * @return max - chebyshev distance between the vectors.
 */
double Distances::chebyshev(const vector<double> &v1, const vector<double> &v2) {
    vector<double> distances = fillDistances(v1, v2);
    double max = 0;
    for (double distance : distances) {
        if (distance > max) {
            max = distance;
        }
    }
    return max;
}

/**
 * Fills a vector of distances between vector points.
 * @param v1 first vector.
 * @param v2 second vector.
 * @return distances vector.
 */
vector<double> Distances::fillDistances(vector<double> v1, vector<double> v2) {
    vector<double> distances;
    distances.reserve(v1.size());
for (int i = 0; i < v1.size(); i++) {
        distances.push_back(std::abs(v1[i] - v2[i]));
    }
    return distances;
}

/**
 * Fill the vector of sums between vector points.
 * @param v1 first vector.
 * @param v2 second vector.
 * @return sums vector.
 */
vector<double> Distances::fillSums(vector<double> v1, vector<double> v2) {
    vector<double> sums;
    sums.reserve(v1.size());
for (int i = 0; i < v1.size(); i++) {
        sums.push_back(std::abs(v1[i])+std::abs(v2[i]));
    }
    return sums;
}
