//
// Created by alik on 1/18/23.
//

#include "Upload.h"
#include "Utilities.h"
#include <thread>
#include <chrono>

Upload::Upload(DefaultIO *dio) : Command(dio) {
    this->description = "1. upload an unclassified csv data file";
}
/**
 * The clients uploads 2 files, a train flies that's already classified and a test files that will be classified.
 * the function organises the files into vector that can be classified and their validity is checked. if the vectors
 * are invalid the vectors are not updated and an error is thrown.
 * @param config
 */
void Upload::execute(Configuration *config) {
    vector<Classified> backup_vec = config->getTrainVectors();
    dio->write("Please upload your local train CSV file.");
    string train_vectors;
    while (true) {
        string current_vector = dio->read();
        if (current_vector == "ret") {
            return;
        }
        train_vectors += current_vector;
        if (current_vector.size() < 4096) {
            break;
        }
    }
    vector<Classified> classified;
    stringstream ss_train(train_vectors);
    string line;
    while (getline(ss_train, line)) {
        if (checkClassifiedVec(line)) {
            stringstream vector_stream(line);
            string number;
            vector<double> vector;
            while (getline(vector_stream, number, ',')) {
                if (!isNumeric(number)) {
                    classified.emplace_back(vector, number);
                    break;
                }
                vector.push_back(stod(number));
            }
        }
    }
    dio->write("Upload Complete.");
    std::this_thread::sleep_for(std::chrono::milliseconds(1));
    dio->write("Please upload your local test CSV file.");
    string test_vectors;
    while (true) {
        string current_vector = dio->read();
        if (current_vector == "ret") {
            config->setTrainVectors(backup_vec);
            return;
        }
        test_vectors += current_vector;
        if (current_vector.size() < 4096) {
            break;
        }
    }
    vector<vector<double>> unclassified;
    stringstream ss_test(test_vectors);
    while (getline(ss_test, line)) {
        stringstream vector_stream(line);
        string number;
        vector<double> vector;
        while (getline(vector_stream, number, ',')) {
            if (isNumeric(number)) {
                vector.push_back(stod(number));
            }
        }
        unclassified.push_back(vector);
    }
    if (!checkVectors(classified, unclassified)) {
        dio->write("Vectors are invalid, please upload again.");
        return;
    }
    config->setTrainVectors(classified);
    config->setTestVectors(unclassified);
    config->setExecute(true, 0);
    dio->write("Upload complete.");
}