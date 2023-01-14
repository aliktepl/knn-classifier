//
// Created by alikt on 05/12/2022.
//

#include "kNearestNeighbors.h"

/**
 * KNN constructor
 * @param classified1 -  a vector of classified vectors.
 * @param unclassified - user input vector.
 * @param k - the k.
 */
kNearestNeighbors::kNearestNeighbors(vector<Classified> classified1, vector<double> unclassified, int k) {
    this->classified = std::move(classified1);
    this->unclassified = std::move(unclassified);
    this->k = k;
}

/**
 *
 * @param distance - distance function.
 * @param p - p for minkowski distance.
 * @return a pair of the classified vector and it's distance from unclassified vectors.
 */
vector<pair<Classified, double>> kNearestNeighbors::calculateDistances(const string& distance, int p) {
    vector<pair<Classified, double>> pairs;
    if (distance == "AUC") {
        for (Classified i : classified) {
            pairs.emplace_back(i, Distances::euclidean(i.getVector(), unclassified));
        }
    }
    if (distance == "MAN") {
        for (Classified i : classified) {
            pairs.emplace_back(i, Distances::minkowski(i.getVector(), unclassified, 1));
        }
    }
    if (distance == "CAN") {
        for (Classified i : classified) {
            pairs.emplace_back(i, Distances::canberra(i.getVector(), unclassified));
        }
    }
    if (distance == "CHB") {
        for (Classified i: classified) {
            pairs.emplace_back(i, Distances::chebyshev(i.getVector(), unclassified));
        }
    }
    if (distance == "MIN") {
        for (Classified i : classified) {
            pairs.emplace_back(i, Distances::minkowski(i.getVector(), unclassified, p));
        }
    }

    make_heap(pairs.begin(), pairs.end(), compare);
    return pairs;
}
/**
 * Create a map with categories as keys and the number of times they appear in the closest k distances.
 * @param pairs - a heap of pairs of classified vectors and their distances.
 * @return the category that appears the most.
 */
string kNearestNeighbors::mapDistances(vector<pair<Classified, double>> pairs) const {
    map<string, int> distance_map;
    //fill the map
    for (int i = 0; i < this->k; ++i) {
        //if the category doesn't exist add it.
        if (distance_map.count(pairs.front().first.getCategory()) == 0) {
            distance_map.insert({pairs.front().first.getCategory(), 1});
        } else {
            //if it exists increment the value.
            distance_map[pairs.front().first.getCategory()]++;
        }
        //pop the top value from the heap.
        pop_heap(pairs.begin(), pairs.end(), compare);
        pairs.pop_back();
    }
    pair<string, int> max(distance_map.begin()->first,distance_map.begin()->second);
    for (pair<string, int> it : distance_map) {
        if (it.second > max.second){
            max = it;
        }
    }
    //return the most common category.
    return max.first;
}

/**
 * Comparator for the heap functions.
 * @param a - the first pair.
 * @param b - the second pair.
 * @return if it is smaller or larger
 */
bool kNearestNeighbors::compare(pair<Classified, double>& a, pair<Classified,double>& b) {
    return a.second > b.second;
}