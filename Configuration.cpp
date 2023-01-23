//
// Created by roi on 1/19/23.
//

#include "Configuration.h"

#include <utility>

Configuration::Configuration() {
    this->k = 5;
    this->metric = "AUC";
}

Configuration::~Configuration() = default;

int Configuration::getK() const {
    return this->k;
}

void Configuration::setMetric(string dist) {
    this->metric = std::move(dist);
}

void Configuration::setK(int x) {
    this->k = x;
}

string Configuration::getMetric() {
    return this->metric;
}

vector<Classified> Configuration::getTrainVectors() {
    return this->trainVectors;
}

vector<vector<double>> Configuration::getTestVectors() {
    return this->testVectors;
}

void Configuration::setTrainVectors(vector<Classified> vector) {
    this->trainVectors = std::move(vector);
}

void Configuration::setTestVectors(vector<vector<double>> vector) {
    this->testVectors = std::move(vector);
}

void Configuration::setExecute(bool option, int index) {
    this->executes[index] = option;
}

vector<bool> Configuration::getExecutes() {
    return this->executes;
}

void Configuration::setClassifications(vector<string> strings) {
    this->classifications = std::move(strings);
}

vector<string> Configuration::getClassifications() {
    return this->classifications;
}
