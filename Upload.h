//
// Created by alik on 1/18/23.
//

#ifndef AX1_EX4_UPLOAD_H
#define AX1_EX4_UPLOAD_H

#include "Command.h"

class Upload: public Command {
public:
    explicit Upload(DefaultIO *dio);
    void execute(Configuration *config) override;
    vector<Classified> createClassifiedVector(const string& train_vectors);
};


#endif //AX1_EX4_UPLOAD_H
