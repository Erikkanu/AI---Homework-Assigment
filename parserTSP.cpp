#include "parserTSP.h"
#include <iostream>
#include <fstream>
#include <sstream>

std::vector<City> parseTSPInstance(const std::string& filename) {
    std::vector<City> cities;

    // Open the file
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error: Unable to open file " << filename << std::endl;
        return cities; // Return empty vector if file cannot be opened
    }

    std::string line;
    bool readingNodes = false;
    while (std::getline(file, line)) {
        // Check for the beginning of the NODE_COORD_SECTION
        if (line.find("NODE_COORD_SECTION") != std::string::npos) {
            readingNodes = true;
            continue;
        }

        // Stop reading if EOF or SECTION
        if (line == "EOF" || line.find("SECTION") != std::string::npos) {
            break;
        }

        // Parse the coordinates if reading nodes
        if (readingNodes) {
            std::stringstream ss(line);
            City city;
            ss >> city.id >> city.x >> city.y;
            cities.push_back(city);
        }
    }

    // Close the file
    file.close();

    return cities;
}
