//
// Created by alik on 1/18/23.
//

#include "Classify.h"
#include "kNearestNeighbors.h"
/**
 * classifies the input vectors
 * @param dio - the input/output interface
 */
Classify::Classify(DefaultIO *dio) : Command(dio) {
    this->description = "3. classify data";
}
/**
 * executes knn algorithm.
 * @param config - necessary shared data.
 */
void Classify::execute(Configuration *config) {
    if (!config->getExecutes()[0]) {
        dio->write("please upload data");
        return;
    }
    //default p value for the minkowski distance;
    int p = 2;
    vector<string> classifications;
    for (const vector<double>& unclassified : config->getTestVectors()) {
        kNearestNeighbors knn(config->getTrainVectors(), unclassified , config->getK());
        string cat = knn.mapDistances(knn.calculateDistances(config->getMetric(), p));
        classifications.push_back(cat);
    }
    config->setClassifications(classifications);
    config->setExecute(true, 2);
    dio->write("classifying data complete.");
}
