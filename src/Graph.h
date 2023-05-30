#ifndef PROJ2_GRAPH_H
#define PROJ2_GRAPH_H


#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <unordered_map>

class Graph {

private:
    std::unordered_map<int, std::unordered_map<int, double>> adj;

public:
    void addEdge(int source, int destination, double distance);

    void printGraph() const;

    const std::unordered_map<int, std::unordered_map<int, double>> &getAdj() const;

    void setAdj(const std::unordered_map<int, std::unordered_map<int, double>> &adj);

};


#endif