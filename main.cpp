#include <iostream>
#include "parserTSP.h"
#include "utilsTSP.h"

int main() {

    // Read the .tsp file which needs to be parsed
    std::string filename = "ulysses22.tsp";

    // Parse the TSP instance file
    std::vector<City> cities = parseTSPInstance(filename);

    // Calculate the distance matrix using city coordinates
    std::vector<std::vector<int>> distanceMatrix = calculateDistanceMatrix(cities);

    // Print the parsed city coordinates
    for (const auto& city : cities) {
        std::cout << "City " << city.id << ": (" << city.x << ", " << city.y << ")" << std::endl;
    }
    std::cout << std::endl;

    // Print the distance matrix for the cities
    std::cout << "Distance Matrix:" << std::endl;
    for (const auto& row : distanceMatrix) {
        for (int distance : row) {
            std::cout << distance << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;

    // Solve the TSP using the specified search algorithms
    solveTSP(distanceMatrix);

    return 0;
}
