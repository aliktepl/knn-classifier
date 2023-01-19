//
// Created by roi on 1/19/23.
//

#include "Configuration.h"
Configuration::Configuration() {

}

Configuration::~Configuration() {

}

string Configuration::getTrainPath() {
    return this->trainPath;
}

string Configuration::getTestPath() {
    return this->testPath;
}

int Configuration::getK() {
    return this->k;
}

void Configuration::setTrainPath(string path) {
    this->trainPath = path;
}

void Configuration::setTestPath(string path) {
    this->testPath = path;
}

void Configuration::setMetric(string dist) {
    this->metric = dist;
}

void Configuration::setK(int x) {
    this->k = x;
}

string Configuration::getMetric() {
    return this->metric;
}
