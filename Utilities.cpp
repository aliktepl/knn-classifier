//
// Created by roi on 1/19/23.
//

#include "Utilities.h"
/**
 * checks if passed string is numerical, if it is returns true.
 * @param str string to check
 * @return true if numeric, false if not
 */
bool isInt(string str) {
    for (auto c: str) {
        if(!isdigit(c)){
            return false;
        }
    }
    return true;
}

//bool isNumeric(string str) {
//    int pointCount = 0, iterCount = 0, length = str.length();
//
//    for (auto c: str) {
//        if (c == '.' && pointCount == 0 && 0 < iterCount < length - 1) {
//            pointCount++;
//        } else if (!isdigit(c)) {
//            return false;
//        }
//        iterCount++;
//    }
//    return true;
//}
/**
 * Checks if a number is contained in a vector.
 * @param numVector is the vector
 * @param num is the number
 * @return true if number is in vector
 */
bool isContained(vector<int> numVector, int num){
    for(auto x: numVector){
        if(num == x){
            return true;
        }
    }
    return false;
}