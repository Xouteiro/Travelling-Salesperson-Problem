

#ifndef PROJ2_FUNCTIONS_H
#define PROJ2_FUNCTIONS_H

#include "Graph.h"
#include <chrono>
#include <iostream>



double tspBacktracking(const Graph& graph);


void tspBacktrackingAux(const Graph& graph, std::vector<bool>& v, int currPos,
             int n, int count, double cost, double& ans);




#endif