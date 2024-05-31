#pragma once
#include <vector>
#include "parserTSP.h"

// Function to calculate the Euclidean distance between two cities
double calculateDistance(const City& city1, const City& city2);

// Function to calculate the distance matrix for a vector of cities
std::vector<std::vector<int>> calculateDistanceMatrix(const std::vector<City>& cities);

// Function to solve TSP using different search algorithms and print the results
void solveTSP(const std::vector<std::vector<int>>& distanceMatrix);