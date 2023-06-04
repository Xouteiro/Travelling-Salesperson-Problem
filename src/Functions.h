#ifndef PROJ2_FUNCTIONS_H
#define PROJ2_FUNCTIONS_H


#include "Graph.h"


/**
 * @brief TSP Backtracking algorithm
 * @param graph Graph to be analyzed
 * @return cost of the path
 * @details Time complexity: O(|N|!)
 */
double tspBacktracking(const Graph& graph);

/**
 * @brief Auxiliary function for the TSP Backtracking algorithm
 * @param graph graph to be analyzed
 * @param visited vector that keeps track of the nodes that have already been visited
 * @param current current node that is being visited
 * @param visitedCount number of nodes that have already been visited
 * @param cost cost of the path
 * @param res minimum cost of the path
 */
void tspBacktrackingAux(const Graph& graph, vector<bool>& v, int currPos, int count, double cost, double& ans);

/**
 * @brief TSP Triangular Approximation Heuristic
 * @param graph graph to be analyzed
 * @return pair of the path and its cost
 * @details Time complexity: O(|N|^2)
 */
pair<vector<int>, double> tspTriangularAppHeuristic(const Graph& graph);

/**
 * @brief Compare two edges by their distance
 * @param edge1 First edge
 * @param edge2 Second edge
 * @return True if the first edge has a smaller weight than the second edge
 */
bool compareEdges(const pair<pair<int, int>, double>& edge1, const pair<pair<int, int>, double>& edge2);

/**
 * @brief Kruskal's algorithm to find the minimum spanning tree of a graph
 * @param graph Graph to be analyzed
 * @return Minimum spanning tree of the graph
 * @details Time complexity: O(|E| * log(|E|)
 */
Graph kruskalMST(const Graph& graph);

/**
 * @brief Depth-first search traversal
 * @param graph graph to be analyzed
 * @return vector with the traversal path
 */
vector<int> dfsTraversal(const Graph& graph);

/**
 * @brief Auxiliary function for dfsTraversal
 * @param graph graph to be analyzed
 * @param visited vector that keeps track of the nodes that have already been visited
 * @param current current node that is being visited
 * @param traversal the vector that keeps the traversal path
 */
void dfsAux(const Graph& graph, vector<bool>& visited, int current, vector<int>& traversal);

/**
 * @brief TSP Nearest Neighbor heuristic
 * @param graph graph to be analyzed
 * @return pair of the path and its cost
 * @details Time complexity: O(|N|^2)
 */
pair<vector<int>, double> nearestNeighbor(const Graph& graph);

/**
 * @brief Calculates the real world distance between the coordinates of two nodes
 * @param node1
 * @param node2
 * @return the distance in kilometers
 */
double distance(const Node& node1, const Node& node2);

#endif