#pragma once
#include <vector>
#include <string>

struct City {
    int id;
    double x;
    double y;
};

std::vector<City> parseTSPInstance(const std::string& filename);
