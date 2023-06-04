#include "Graph.h"


void Graph::addEdge(int source, int destination, double distance) {
    adj[source][destination] = distance;
    adj[destination][source] = distance;
}

void Graph::printGraph() const {
    for (const auto& entry : this->getAdj()) {
        int source = entry.first;
        const auto& destinations = entry.second;
        cout << "Source: " << source << "\n";
        for (const auto& destination : destinations) {
            cout << "  Destination: " << destination.first << ", Distance: " << destination.second << "\n";
        }
    }
}

const unordered_map<int, unordered_map<int, double>> &Graph::getAdj() const {
    return adj;
}

void Graph::setAdj(const unordered_map<int, unordered_map<int, double>> &adj) {
    Graph::adj = adj;
}

void Graph::addNode(Node node) {
    nodes.push_back(node);
}

const vector<Node> &Graph::getNodes() const {
    return nodes;
}

void Graph::setNodes(const vector<Node> &nodes) {
    Graph::nodes = nodes;
}
