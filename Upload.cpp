//
// Created by alik on 1/18/23.
//

#include "Upload.h"
#include "FileReader.h"

Upload::Upload(DefaultIO *dio) : Command(dio) {
    this->description = "1. upload an unclassified csv data file";
}
void Upload::execute(Configuration *config) {
    dio->write("Please upload your local train CSV file.");
    string train_vectors;
    while (true) {
        string current_vector = dio->read();
        if (current_vector == "0"){
            break;
        }
        train_vectors += current_vector;
    }
    dio->write("Please upload your local test CSV file.");
    string test_vectors;
    while (true) {
        string current_vector = dio->read();
        if (current_vector == "0") {
            break;
        }
        test_vectors += current_vector;
    }
    config->setExecute(true, 0);
    dio->write("Upload complete.");
}

vector<Classified> Upload::createClassifiedVector(const string& train_vectors) {
    vector<Classified> classified;
    vector<double> vector;
    stringstream ss(train_vectors);
    string line;
    bool flag = false;
    while (getline(ss, line, '\n')) {
        for (auto x: line) {
            if (!isdigit(x) && x != '.') { flag = true; }
        }
        if (flag) { break; }
        vector.push_back(stod(line));
    }
    return classified;
}