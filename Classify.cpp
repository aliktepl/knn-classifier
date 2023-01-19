//
// Created by alik on 1/18/23.
//

#include "Classify.h"
#include "kNearestNeighbors.h"

Classify::Classify(DefaultIO *dio) : Command(dio) {
    this->description = "3. classify data";
}

void Classify::execute() {
    //default p value for the minkowski distance;
    int p = 2;
    vector<Classified> classifiedVectors;
    string distance;
    vector<double> input;
    int k = 5;
    kNearestNeighbors knn(classifiedVectors, input, k);
    string cat = knn.mapDistances(knn.calculateDistances(distance, p));
    dio->write("classifying data complete.");
}
