#include "Functions.h"


double tspBacktracking(const Graph& graph) {
    int n = int(graph.getAdj().size());
    vector<bool> visited(n, false);
    visited[0] = true;
    int current = 0, visitedCount = 1;
    double cost = 0, res = INT_MAX;

    tspBacktrackingAux(graph, visited, current, visitedCount, cost, res);

    return res;
}

void tspBacktrackingAux(const Graph& graph, vector<bool>& visited, int current, int visitedCount, double cost, double& res) {
    int n = int(graph.getAdj().size());
    if (visitedCount == n && graph.getAdj().at(current).count(0)) {
        res = min(res, cost + graph.getAdj().at(current).at(0));
        return;
    }

    for (const auto& neighbor : graph.getAdj().at(current)) {
        int i = neighbor.first;
        double weight = neighbor.second;
        if (!visited[i]) {
            visited[i] = true;
            tspBacktrackingAux(graph, visited, i, visitedCount + 1, cost + weight, res);
            visited[i] = false;
        }
    }
}

pair<vector<int>, double> tspTriangularAppHeuristic(const Graph& graph) {
    // create minimum spanning tree using kruskal's algorithm
    Graph mst = kruskalMST(graph);
    // create the path through a dfs traversal
    vector<int> traversal = dfsTraversal(mst);
    double cost = 0;

    // sum of edges in dfs preorder traversal path
    for(int i = 0 ; i < traversal.size() - 1 ; i++) {
        // if the edge exists in the original graph, add its weight
        if(graph.getAdj().at(traversal[i]).find(traversal[i + 1]) != graph.getAdj().at(traversal[i]).end())
            cost += graph.getAdj().at(traversal[i]).at(traversal[i + 1]);
        // else, add the real world distance between the two nodes
        else
            cost += distance(graph.getNodes()[traversal[i]], graph.getNodes()[traversal[i + 1]]);
    }
    return make_pair(traversal, cost);
}


bool compareEdges(const pair<pair<int, int>, double>& edge1, const pair<pair<int, int>, double>& edge2) {
    return edge1.second < edge2.second;
}

Graph kruskalMST(const Graph& graph) {
    Graph mstGraph;

    const unordered_map<int, unordered_map<int, double>>& adj = graph.getAdj();
    vector<pair<pair<int, int>, double>> edges;
    for (const auto& entry : adj) {
        int source = entry.first;
        for (const auto& neighbor : entry.second) {
            int destination = neighbor.first;
            double distance = neighbor.second;
            edges.push_back(make_pair(make_pair(source, destination), distance));
        }
    }
    // step 1 - sort the edges by ascending order of distance
    sort(edges.begin(), edges.end(), compareEdges);

    UnionFind uf(graph.getNodes().size());

    // step 2 - add the edges to the MST in ascending order of weight
    // if the edge does not create a cycle
    for (const auto& edge : edges) {
        int source = edge.first.first;
        int destination = edge.first.second;

        int rootSource = uf.find(source);
        int rootDestination = uf.find(destination);

        if (rootSource != rootDestination) {
            mstGraph.addEdge(source, destination, edge.second);
            uf.unite(rootSource, rootDestination);
        }
    }

    return mstGraph;
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

double distance(const Node& node1, const Node& node2) {
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
