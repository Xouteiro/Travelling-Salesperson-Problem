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
#include <cmath>

using namespace std;

class Graph {

private:
    unordered_map<int, unordered_map<int, double>> adj;
    vector<Node> nodes;
public:
    void addEdge(int source, int destination, double distance);

    void printGraph() const;

    const unordered_map<int, unordered_map<int, double>> &getAdj() const;

    void setAdj(const unordered_map<int, unordered_map<int, double>> &adj);

    void addNode(Node node);

    const vector<Node> &getNodes() const;

    void setNodes(const vector<Node> &nodes);

    void printNodes() const;
};


#endif