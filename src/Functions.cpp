#include "Functions.h"


double tspBacktracking(const Graph& graph) {
    int n = int(graph.getAdj().size());
    vector<bool> visited(n, false);
    visited[0] = true;
    int current = 0, visitedCount = 1;
    double cost = 0, res = INT_MAX;

    tspBacktrackingAux(graph, visited, current, n, visitedCount, cost, res);

    return res;
}

void tspBacktrackingAux(const Graph& graph, vector<bool>& v, int current,
             int n, int visitedCount, double cost, double& res) {

    if (visitedCount == n && graph.getAdj().at(current).count(0)) {
        res = min(res, cost + graph.getAdj().at(current).at(0));
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

pair<vector<int>, double> tspTriangularAppHeuristic(const Graph& graph){
    // create minimum spanning tree
    Graph mst = primMST(graph);
    // create the path through a dfs
    vector<int> traversal = dfsTraversal(mst);
    double cost = 0;

    // sum of edges in dfs preorder traversal path
    for(int i = 0 ; i < traversal.size() - 1 ; i++) {
        if(graph.getAdj().at(traversal[i]).find(traversal[i + 1]) != graph.getAdj().at(traversal[i]).end())
            cost += graph.getAdj().at(traversal[i]).at(traversal[i + 1]);
        else
            cost += distance(graph.getNodes()[traversal[i]], graph.getNodes()[traversal[i + 1]]);
    }
    return make_pair(traversal, cost);
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

vector<int> dfsTraversal(const Graph& graph) {
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


// Nearest Neighbor algorithm for TSP
pair<vector<int>, double> nearestNeighbor(const Graph& graph) {
    int startNode = 0;
    const unordered_map<int, unordered_map<int, double>>& adj = graph.getAdj();

    if (adj.count(startNode) == 0) {
        cout << "Invalid startNode: " << startNode << std::endl;
        return make_pair(vector<int>(), 0.0);
    }

    vector<int> tour;
    vector<bool> visited(adj.size(), false);
    double totalCost = 0.0;

    int current = startNode;
    visited[current] = true;
    tour.push_back(current);

    while (tour.size() < adj.size()) {
        double minDistance = INT_MAX;
        int nextNode = -1;

        const unordered_map<int, double>& currentNeighbors = adj.at(current);

        for (const auto& neighbor : currentNeighbors) {
            int neighborNode = neighbor.first;
            double distance = neighbor.second;

            if (!visited[neighborNode] && distance < minDistance) {
                minDistance = distance;
                nextNode = neighborNode;
            }
        }

        if (nextNode != -1) {
            tour.push_back(nextNode);
            visited[nextNode] = true;
            totalCost += minDistance;
            current = nextNode;
        }
        else {
            cout << "Invalid adjacency matrix. Graph may be disconnected." << endl;
            return make_pair(vector<int>(), 0.0);
        }
    }

    // Add the cost of returning to the start node
    totalCost += adj.at(tour.back()).at(startNode);

    return make_pair(tour, totalCost);
}

double distance(const Node& node1, const Node& node2){
    double lat1 = node1.getX();
    double lat2 = node2.getX();
    double lon1 = node1.getY();
    double lon2 = node2.getY();
    int earthRadius = 6371000; // metres
    double latitudeSource = lat1 * M_PI / 180;
    double latitudeDestination = lat2 * M_PI / 180;
    double latitudeDiff = (lat2 - lat1) * M_PI / 180;
    double longitudeDiff = (lon2 - lon1) * M_PI / 180;

    double a = sin(latitudeDiff / 2) * sin(latitudeDiff / 2) +
               cos(latitudeSource) * cos(latitudeDestination) *
               sin(longitudeDiff / 2) * sin(longitudeDiff / 2);

    double c = 2 * atan2(sqrt(a), sqrt(1 - a));

    return earthRadius * c / 1000; // in km
}
