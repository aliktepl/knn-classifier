//
// Created by alik on 1/18/23.
//

#include "Upload.h"

Upload::Upload(DefaultIO *dio) : Command(dio) {
    this->description = "1. upload an unclassified csv data file";
}
void Upload::execute(Configuration* config) {
    string train_path = dio->read();
    dio->write("Please upload your local train CSV file.");
    string test_path = dio->read();
    dio->write("Please upload your local test CSV file.");

    dio->write("Upload complete.");
}
