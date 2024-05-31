#include "LCS.h"
#include <queue>
#include <limits>

LCS::LCS(const std::vector<std::vector<int>>& distanceMatrix)
    : TSP(distanceMatrix) {}

int LCS::leastCostSearch() {
    // Define a structure to represent the state of the search
    struct State {
        int node;
        int cost;
        std::vector<bool> visited;
        int pathLength;

        // Comparison function to prioritize states in the priority queue
        bool operator>(const State& other) const {
            return cost > other.cost;
        }
    };

    int minCost = std::numeric_limits<int>::max();

    // Perform least-cost search starting from each city
    for (int startNode = 0; startNode < numberOfNodes; ++startNode) {
        std::priority_queue<State, std::vector<State>, std::greater<State>> pq;

        // Start from the current start node
        State initialState = { startNode, 0, std::vector<bool>(numberOfNodes, false), 1 };
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
                    newState.visited[i] = true;
                    newState.pathLength++;
                    pq.push(newState);
                }
            }
        }
    }

    return minCost;
}
