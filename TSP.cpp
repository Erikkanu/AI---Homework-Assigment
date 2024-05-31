#include "TSP.h"

TSP::TSP(const std::vector<std::vector<int>>& distanceMatrix)
    : distanceMatrix(distanceMatrix), numberOfNodes(distanceMatrix.size()) {}

const std::vector<std::vector<int>>& TSP::getDistanceMatrix() const {
    return distanceMatrix;
}

int TSP::getNumberOfNodes() const {
    return numberOfNodes;
}
