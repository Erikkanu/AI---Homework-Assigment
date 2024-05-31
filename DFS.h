#pragma once
#include "TSP.h"

class DFS : public TSP {
public:
    // Constructor to initialize DFS with a distance matrix
    DFS(const std::vector<std::vector<int>>& distanceMatrix);

    // Function to perform depth-first search for solving TSP
    int depthFirstSearch();

private:
    // Recursive function for depth-first search
    void dfs(int startNode, int currentNode, std::vector<bool>& visited, int currentCost, int& minCost);
};
