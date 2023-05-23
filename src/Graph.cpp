#include "Graph.h"

void Graph::addEdge(int source, int destination, double distance) {
    adj[source][destination] = distance;
    adj[destination][source] = distance;
}


void Graph::printGraph(const std::unordered_map<int, std::unordered_map<int, double>>& graph) {
    for (const auto& entry : graph) {
        int source = entry.first;
        const auto& destinations = entry.second;
        std::cout << "Source: " << source << "\n";
        for (const auto& destination : destinations) {
            std::cout << "  Destination: " << destination.first << ", Distance: " << destination.second << "\n";
        }
    }
}

const std::unordered_map<int, std::unordered_map<int, double>> &Graph::getAdj() const {
    return adj;
}

void Graph::setAdj(const std::unordered_map<int, std::unordered_map<int, double>> &adj) {
    Graph::adj = adj;
}


