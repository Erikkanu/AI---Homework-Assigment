#include "DFS.h"
#include <limits>

DFS::DFS(const std::vector<std::vector<int>>& distanceMatrix)
    : TSP(distanceMatrix) {}

void DFS::dfs(int startNode, int currentNode, std::vector<bool>& visited, int currentCost, int& minCost) {
    visited[currentNode] = true;

    // Check if all cities are visited
    bool allVisited = true;
    for (bool v : visited) {
        if (!v) {
            allVisited = false;
            break;
        }
    }

    // If all cities are visited, calculate the total cost and update the minimum cost
    if (allVisited) {
        currentCost += distanceMatrix[currentNode][startNode]; // Return to the start city
        if (currentCost < minCost) {
            minCost = currentCost;
        }
    }
    // Otherwise, continue exploring paths recursively
    else {
        for (int i = 0; i < numberOfNodes; ++i) {
            if (!visited[i] && distanceMatrix[currentNode][i] != std::numeric_limits<int>::max()) {
                dfs(startNode, i, visited, currentCost + distanceMatrix[currentNode][i], minCost);
            }
        }
    }

    visited[currentNode] = false;
}

int DFS::depthFirstSearch() {
    int minCost = std::numeric_limits<int>::max();

    // Perform DFS starting from each city and update the minimum cost
    for (int startNode = 0; startNode < numberOfNodes; ++startNode) {
        std::vector<bool> visited(numberOfNodes, false);
        dfs(startNode, startNode, visited, 0, minCost);
    }

    return minCost;
}
