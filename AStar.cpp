#include "AStar.h"
#include <queue>
#include <vector>
#include <limits>
#include <algorithm>
#include <functional>

AStar::AStar(const std::vector<std::vector<int>>& distanceMatrix)
    : TSP(distanceMatrix) {}

int AStar::aStarSearch() {
    // Define a structure to represent the state of the search
    struct State {
        int node;
        int cost;
        int heuristic;
        std::vector<bool> visited;
        int pathLength;

        // Comparison function to prioritize states in the priority queue
        bool operator>(const State& other) const {
            return (cost + heuristic) > (other.cost + other.heuristic);
        }
    };

    int minCost = std::numeric_limits<int>::max();

    // Perform A* search starting from each city
    for (int startNode = 0; startNode < numberOfNodes; ++startNode) {
        std::priority_queue<State, std::vector<State>, std::greater<State>> pq;

        // Start from the current start node
        State initialState = { startNode, 0, heuristic(std::vector<bool>(numberOfNodes, false)), std::vector<bool>(numberOfNodes, false), 1 };
        initialState.visited[startNode] = true;
        pq.push(initialState);

        while (!pq.empty()) {
            State currentState = pq.top();
            pq.pop();

            // Check if a complete path is found
            if (currentState.pathLength == numberOfNodes) {
                int totalCost = currentState.cost + distanceMatrix[currentState.node][startNode]; // Return to the start city
                if (totalCost < minCost) {
                    minCost = totalCost;
                }
                continue;
            }

            // Explore neighbors and add them to the priority queue
            for (int i = 0; i < numberOfNodes; ++i) {
                if (!currentState.visited[i] && distanceMatrix[currentState.node][i] != std::numeric_limits<int>::max()) {
                    State newState = currentState;
                    newState.node = i;
                    newState.cost += distanceMatrix[currentState.node][i];
                    newState.heuristic = heuristic(newState.visited);
                    newState.visited[i] = true;
                    newState.pathLength++;
                    pq.push(newState);
                }
            }
        }
    }

    return minCost;
}

int AStar::heuristic(const std::vector<bool>& visited) {
    // Calculate the heuristic based on the minimum spanning tree cost
    return primMST(visited);
}

int AStar::primMST(const std::vector<bool>& visited) {
    // Initialize key values and whether vertices are included in the MST
    std::vector<int> key(numberOfNodes, std::numeric_limits<int>::max());
    std::vector<bool> inMST(numberOfNodes, false);

    // Start from an arbitrary unvisited node
    int startNode = -1;
    for (int i = 0; i < numberOfNodes; ++i) {
        if (!visited[i]) {
            startNode = i;
            break;
        }
    }

    // All nodes are visited, return 0
    if (startNode == -1) return 0;

    // Set key value of the start node to 0
    key[startNode] = 0;

    // Construct the MST
    for (int count = 0; count < numberOfNodes - 1; ++count) {
        int u = -1;

        // Pick the minimum key vertex from the set of vertices not yet included in MST
        for (int i = 0; i < numberOfNodes; ++i) {
            if (!inMST[i] && (u == -1 || key[i] < key[u])) {
                u = i;
            }
        }

        // Update u as part of MST
        if (u == -1 || visited[u]) continue;

        inMST[u] = true;

        // Update key values and find adjacent vertices of the picked vertex
        for (int v = 0; v < numberOfNodes; ++v) {
            if (!inMST[v] && !visited[v] && distanceMatrix[u][v] < key[v]) {
                key[v] = distanceMatrix[u][v];
            }
        }
    }

    // Calculate the total cost of the MST
    int mstCost = 0;
    for (int i = 0; i < numberOfNodes; ++i) {
        if (!visited[i]) {
            mstCost += key[i];
        }
    }

    return mstCost;
}
