#include "utilsTSP.h"
#include "DFS.h"
#include "LCS.h"
#include "AStar.h"
#include <iostream>
#include <chrono>
#include <cmath>

double calculateDistance(const City& city1, const City& city2) {
    return std::sqrt(std::pow(city1.x - city2.x, 2) + std::pow(city1.y - city2.y, 2));
}

std::vector<std::vector<int>> calculateDistanceMatrix(const std::vector<City>& cities) {
    int numberOfCities = cities.size();
    std::vector<std::vector<int>> distanceMatrix(numberOfCities, std::vector<int>(numberOfCities, 0));

    for (int i = 0; i < numberOfCities; ++i) {
        for (int j = 0; j < numberOfCities; ++j) {
            if (i != j) {
                distanceMatrix[i][j] = static_cast<int>(std::round(calculateDistance(cities[i], cities[j])));
            }
        }
    }

    return distanceMatrix;
}

void solveTSP(const std::vector<std::vector<int>>& distanceMatrix) {
    // Solve TSP using Depth-First Search
    auto startDFS = std::chrono::high_resolution_clock::now();
    DFS dfsSolver(distanceMatrix);
    int dfsResult = dfsSolver.depthFirstSearch();
    auto endDFS = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsedDFS = endDFS - startDFS;
    std::cout << "The minimum cost using Depth-First Search is: " << dfsResult << std::endl;
    std::cout << "Time taken by DFS: " << elapsedDFS.count() << " seconds" << std::endl << std::endl;

    // Solve TSP using Least-Cost Search
    auto startLCS = std::chrono::high_resolution_clock::now();
    LCS lcsSolver(distanceMatrix);
    int lcsResult = lcsSolver.leastCostSearch();
    auto endLCS = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsedLCS = endLCS - startLCS;
    std::cout << "The minimum cost using Least-Cost Search is: " << lcsResult << std::endl;
    std::cout << "Time taken by LCS: " << elapsedLCS.count() << " seconds" << std::endl << std::endl;

    // Solve TSP using A* Search
    auto startAStar = std::chrono::high_resolution_clock::now();
    AStar aStarSolver(distanceMatrix);
    int aStarResult = aStarSolver.aStarSearch();
    auto endAStar = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsedAStar = endAStar - startAStar;
    std::cout << "The minimum cost using A* Search is: " << aStarResult << std::endl;
    std::cout << "Time taken by A* Search: " << elapsedAStar.count() << " seconds" << std::endl;
}
