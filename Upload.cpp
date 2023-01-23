//
// Created by alik on 1/18/23.
//

#include "Upload.h"
#include "FileReader.h"
#include "Utilities.h"

Upload::Upload(DefaultIO *dio) : Command(dio) {
    this->description = "1. upload an unclassified csv data file";
}
void Upload::execute(Configuration *config) {
    string train_path = dio->read();
    dio->write("Please upload your local train CSV file.");
    string train_vectors;
    while (true) {
        string current_vector = dio->read();
        train_vectors += current_vector;
        if (current_vector.size() < 4096){
            break;
        }
    }
    vector<Classified> classified;
    stringstream ss_train(train_vectors);
    string line;
    while (getline(ss_train, line, '\n')) {
        if (checkClassifiedVec(line)) {
            stringstream vector_stream(line);
            string number;
            vector<double> vector;
            bool num_flag = false;
            while (vector_stream >> number) {
                if (!isInt(number)) {
                    num_flag = true;
                    break;
                }
                vector.push_back(stod(number));
            }
            string cat;
            if (num_flag) {
                vector_stream >> cat;
            } else {
                vector.pop_back();
                vector_stream >> cat;
            }
            classified.emplace_back(vector, cat);
        }
    }
    dio->write("Upload Complete.");
    dio->write("Please upload your local test CSV file.");
    string test_vectors;
    while (true) {
        string current_vector = dio->read();
        test_vectors += current_vector;
        if (current_vector.size() < 4096) {
            break;
        }
    }
    vector<vector<double>> unclassified;
    stringstream ss_test(test_vectors);
    while (getline(ss_test, line, '\n')) {
        stringstream vector_stream(line);
        double number;
        vector<double> vector;
        while (vector_stream >> number) {
            vector.push_back(number);
        }
        unclassified.push_back(vector);
    }
    config->setTrainVectors(classified);
    config->setTestVectors(unclassified);
    config->setExecute(true, 0);
    dio->write("Upload complete.");
}