#ifndef PROJ2_FUNCTIONS_H
#define PROJ2_FUNCTIONS_H

#include "Graph.h"

double tspBacktracking(const Graph& graph);


void tspBacktrackingAux(const Graph& graph, vector<bool>& v, int currPos,
             int n, int count, double cost, double& ans);

pair<vector<int>, double> tspTriangularAppHeuristic(const Graph& graph);

Graph primMST(const Graph& graph);

vector<int> dfsTraversal(const Graph& graph);

void dfsAux(const Graph& graph, vector<bool>& visited, int current, vector<int>& traversal);

pair<vector<int>, double> nearestNeighbor(const Graph& graph);

double distance(const Node& node1, const Node& node2);

#endif