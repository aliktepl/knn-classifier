//
// Created by royva on 06/12/2022.
//

#include "FileReader.h"

/**
 * A class that read data from a file.
 * @param path file path
 */
FileReader::FileReader(char *path) {
    this->path = path;
}

/**
 * Destructor
 */
FileReader::~FileReader() = default;

/**
 * This method feeds lines in from .csv file to stream, parses it and checks it's validity.
 * If the row is of kind (vector, category) the method will then instantiate it to 'Classified'
 * and push it to the vector 'FileReader' holds.
 * @return bool, true if the feeding was successful otherwise false
 */
bool FileReader::feedTrainVector() {
    Parser p;
    ifstream inputFile;
    inputFile.open(this->path);
    // try to open file with stream
    if (!inputFile.is_open()) {
        cout << "Cannot open file path" << endl;
        return false;
    }
    string line;
    // iterate rows of file until end of file
    while (getline(inputFile, line)) {
        vector<double> v;
        stringstream ss(line);
        string word, category;
        // parse row with stream for every ',' delimiter in row
        while (getline(ss, word, ',')) {
            // check for end of file
            if (ss.eof()) {
                break;
            }
            /**
             * check each character in 'word' for digit, 'E', '.' and '-'
             * if one of these characters appear then the 'word' is valid.
             */
            for (int i = 0; i < strlen(word.c_str()); i++) {
                if (!isdigit(word[i]) && word.c_str()[i] != 'E' &&
                    word.c_str()[i] != '.' && word.c_str()[i] != '-') {
                    cout << "One of the vectors contains an invalid value" << endl;
                    return false;
                }
            }
            /**
             * parse special characters and check their count
             * if count matches exponent template then parse it and push result to vector
             * otherwise check if special characters appear more than they should and return
             * 'false'. if 'word' passes all checks push it to vector directly.
             */
            p.setDelim('E');
            p.setToParse(word);
            int c1 = p.checkParse();
            p.setDelim('-');
            int c2 = p.checkParse();
            p.setDelim('.');
            int c3 = p.checkParse();
            if (c1 == 1 && (c2 == 0 || c2 == 1 || c2 == 2) && (c3 == 0 || c3 == 1)) {
                v.push_back(p.parse());
            } else if (c1 > 1 || c2 > 2 || c3 > 1) {
                cout << "One of the vectors contains an invalid value" << endl;
                return false;
            } else {
                v.push_back(stod(word));
            }
        }
        this->train_vector.emplace_back(v, word);
        Classified lastClassified = *(train_vector.end() - 1);
        // check for vector length equality between all vectors read
        if (this->size == 0) {
            this->size = lastClassified.getVector().size();
        }
        if (!lastClassified.distValidation(this->size)) {
            cout << "One of the vectors is of different size" << endl;
            return false;
        }
    }
    return true;
}

bool FileReader::feedTestVector() {
    Parser p;
    ifstream inputFile;
    inputFile.open(this->path);
    // try to open file with stream
    if (!inputFile.is_open()) {
        cout << "Cannot open file path" << endl;
        return false;
    }
    string line;
    while (getline(inputFile, line)) {
        vector<double> v;
        stringstream ss(line);
        string word;
        // parse row with stream for every ',' delimiter in row
        while (getline(ss, word, ',')) {
            // check for end of file
            if (ss.eof()) {
                break;
            }
            for (int i = 0; i < strlen(word.c_str()); i++) {
                if (!isdigit(word[i]) && word.c_str()[i] != 'E' &&
                    word.c_str()[i] != '.' && word.c_str()[i] != '-') {
                    cout << "One of the vectors contains an invalid value" << endl;
                    return false;
                }
            }
            p.setDelim('E');
            p.setToParse(word);
            int c1 = p.checkParse();
            p.setDelim('-');
            int c2 = p.checkParse();
            p.setDelim('.');
            int c3 = p.checkParse();
            if (c1 == 1 && (c2 == 0 || c2 == 1 || c2 == 2) && (c3 == 0 || c3 == 1)) {
                v.push_back(p.parse());
            } else if (c1 > 1 || c2 > 2 || c3 > 1) {
                cout << "One of the vectors contains an invalid value" << endl;
                return false;
            } else {
                v.push_back(stod(word));
            }
        }
        this->train_vector.emplace_back(v, word);
    }
    return true;
}

/**
 * Get a vector of classified vectors
 * @return vector of Classified objects
 */
vector<Classified> FileReader::getTrainVector() {
    return this->train_vector;
}

vector<vector<double>> FileReader::getTestVector() {
    return this->test_vector;
}

/**
 * Get the size of a vector in the file
 * @return vector length
 */
unsigned long long FileReader::getSize() const {
    return this->size;
}


