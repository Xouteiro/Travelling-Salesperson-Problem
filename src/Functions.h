#ifndef PROJ2_FUNCTIONS_H
#define PROJ2_FUNCTIONS_H

#include "Graph.h"
#include <iostream>



double tspBacktracking(const Graph& graph);


void tspBacktrackingAux(const Graph& graph, std::vector<bool>& v, int currPos,
             int n, int count, double cost, double& ans);

double tspTriangularAppHeuristic(const Graph& graph);

Graph primMST(const Graph& graph);

std::vector<int> dfsTraversal(const Graph& graph);

void dfsAux(const Graph& graph, std::vector<bool>& visited, int current, std::vector<int>& traversal);

#endif