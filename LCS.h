#pragma once

#include "TSP.h"

class LCS : public TSP {
public:
    // Constructor to initialize LCS with a distance matrix
    LCS(const std::vector<std::vector<int>>& distanceMatrix);

    // Function to perform least-cost search for solving TSP
    int leastCostSearch();
};
