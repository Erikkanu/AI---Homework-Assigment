#pragma once
#include "TSP.h"

class AStar : public TSP {
public:
    // Constructor to initialize A* Search with a distance matrix
    AStar(const std::vector<std::vector<int>>& distanceMatrix);

    // Function to perform A* search for solving TSP
    int aStarSearch();

private:
    // Heuristic function based on Prim's Minimum Spanning Tree
    int heuristic(const std::vector<bool>& visited);

    // Helper function to calculate the minimum spanning tree cost using Prim's algorithm
    int primMST(const std::vector<bool>& visited);
};
