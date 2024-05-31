#pragma once

#include <vector>

class TSP {
public:
    // Constructor to initialize the TSP instance with a distance matrix
    TSP(const std::vector<std::vector<int>>& distanceMatrix);

    // Getter function to retrieve the distance matrix
    const std::vector<std::vector<int>>& getDistanceMatrix() const;

    // Getter function to retrieve the number of nodes
    int getNumberOfNodes() const;

protected:
    std::vector<std::vector<int>> distanceMatrix; // Matrix representing distances between cities
    int numberOfNodes; // Number of cities
};
