#ifndef PROJ2_GRAPH_H
#define PROJ2_GRAPH_H

#include "Node.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <unordered_map>
#include <iomanip>


class Graph {

private:
    std::unordered_map<int, std::unordered_map<int, double>> adj;
    std::vector<Node> nodes;
public:
    void addEdge(int source, int destination, double distance);

    void printGraph() const;

    const std::unordered_map<int, std::unordered_map<int, double>> &getAdj() const;

    void setAdj(const std::unordered_map<int, std::unordered_map<int, double>> &adj);

    void addNode(Node node);

    const std::vector<Node> &getNodes() const;

    void setNodes(const std::vector<Node> &nodes);

    void printNodes() const;
};


#endif