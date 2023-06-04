#ifndef PROJ2_GRAPH_H
#define PROJ2_GRAPH_H


#include "Node.h"
#include "UnionFind.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <unordered_map>
#include <iomanip>
#include <cmath>

using namespace std;


/**
 * @brief This class represents a graph
 */
class Graph {
private:
    unordered_map<int, unordered_map<int, double>> adj;
    vector<Node> nodes;
public:
    /**
     * @brief Adds an edge to the graph
     * @param source source node
     * @param destination destination node
     * @param distance distance between the nodes
     */
    void addEdge(int source, int destination, double distance);

    /**
     * @brief Prints the graph
     */
    void printGraph() const;

    /**
     * @brief Getter for the adjacency list
     * @return the adjacency list
     */
    const unordered_map<int, unordered_map<int, double>> &getAdj() const;

    /**
     * @brief Setter for the adjacency list
     * @param adj the adjacency list
     */
    void setAdj(const unordered_map<int, unordered_map<int, double>> &adj);

    /**
     * @brief Adds a node to the graph
     * @param node node to be added to the graph
     */
    void addNode(Node node);

    /**
     * @brief Getter for the nodes
     * @return the nodes of the graph
     */
    const vector<Node> &getNodes() const;

    /**
     * @brief Setter for the nodes
     * @param nodes the nodes of the graph
     */
    void setNodes(const vector<Node> &nodes);
};


#endif
