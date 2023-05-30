#include "Functions.h"

using namespace std;

double tspBacktracking(const Graph& graph) {
    int n = int(graph.getAdj().size());
    std::vector<bool> visited(n, false);
    visited[0] = true;
    int current = 0, visitedCount = 1;
    double cost = 0, res = INT_MAX;

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

double tspTriangularAppHeuristic(const Graph& graph){
    Graph mst = primMST(graph);
    vector<int> traversal = dfsTraversal(mst);
    double cost = 0;

    // sum of edges in dfs preorder traversal path
    for(int i = 0 ; i < traversal.size() - 1 ; i++)
        cost += graph.getAdj().at(traversal[i]).at(traversal[i+1]);
    return cost;
}

// Function to construct and print MST for
// a graph represented using adjacency
// matrix representation
Graph primMST(const Graph& graph) {
    int n = int(graph.getAdj().size());
    Graph mst;
    vector<bool> visited(n, false);
    unordered_map<int, unordered_map<int, double>> edges;
    int next = 0;

    for(int i = 0 ; i < n ; i++){
        auto entry = graph.getAdj().at(next);
        visited[next] = true;
        int final_v = -1;
        double final_weight = INT_MAX;
        int source = -1;

        for(auto edge : entry){
            edges[next][edge.first] = edge.second; // [destination] = [weight]
        }

        for(const auto& destination : edges){
            for(const auto& edge : destination.second) { // edge = (destination, weight
                double weight = edge.second;
                if (!visited[edge.first] && weight < final_weight) {
                    source = destination.first;
                    final_v = edge.first;
                    final_weight = weight;
                }
            }
        }

        edges[next].erase(final_v);

        if(final_v != -1) {
            mst.addEdge(source, final_v, final_weight);
            next = final_v;
        }
    }

    return mst;
}

vector<int> dfsTraversal(const Graph& graph){
    int n = int(graph.getAdj().size());
    vector<bool> visited(n, false);
    vector<int> traversal;
    int current = 0;

    dfsAux(graph, visited, current, traversal);

    traversal.push_back(0);

    return traversal;
}

void dfsAux(const Graph& graph, vector<bool>& visited, int current, vector<int>& traversal) {
    visited[current] = true;
    traversal.push_back(current);
    for(const auto& neighbor : graph.getAdj().at(current)) {
        int i = neighbor.first;
        if(!visited[i]) {
            dfsAux(graph, visited, i, traversal);
        }
    }
}
