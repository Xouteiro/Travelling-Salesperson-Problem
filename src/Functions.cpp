

#include "Functions.h"

double tspBacktracking(const Graph& graph)
{
    int n = int(graph.getAdj().size());


    std::vector<bool> visited(n, false);
    visited[0] = true;

    int current = 0;
    int visitedCount = 1;
    double cost = 0;

    double res = INT_MAX;

    tspBacktrackingAux(graph, visited, current, n, visitedCount, cost, res);

    return res;// You can perform further actions with the result here
}

void tspBacktrackingAux(const Graph& graph, std::vector<bool>& v, int current,
             int n, int visitedCount, double cost, double& res) {

    if (visitedCount == n && graph.getAdj().at(current).count(0)) {
        res = std::min(res, cost + graph.getAdj().at(current).at(0));
        return;
    }

    // BACKTRACKING STEP
    // Loop to traverse the adjacency list
    // of currPos node and increase the count
    // by 1 and cost by graph[currPos][i] value
    for (const auto& neighbor : graph.getAdj().at(current)) {
        int i = neighbor.first;
        double weight = neighbor.second;
        if (!v[i]) {
            // Mark as visited
            v[i] = true;
            tspBacktrackingAux(graph, v, i, n, visitedCount + 1, cost + weight, res);

            // Mark ith node as unvisited
            v[i] = false;
        }
    }
}