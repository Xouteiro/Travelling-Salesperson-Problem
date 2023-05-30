

#ifndef PROJ2_FUNCTIONS_H
#define PROJ2_FUNCTIONS_H

#include "Graph.h"
#include <iostream>



double tspBacktracking(const Graph& graph);


void tspBacktrackingAux(const Graph& graph, std::vector<bool>& v, int currPos,
             int n, int count, double cost, double& ans);

double tspTriangularAppHeuristic(const Graph& graph);

void tspTriangularAppHeuristicAux(const Graph& graph, std::vector<bool>& v, int current,
                                  int n, int visitedCount, double cost, double& res);


Graph primMST(const Graph& graph);


#endif