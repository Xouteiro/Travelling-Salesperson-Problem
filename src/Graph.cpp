#include "Graph.h"

void Graph::addEdge(int source, int destination, double distance) {
    adj[source][destination] = distance;
    adj[destination][source] = distance;
}


void Graph::printGraph() const {
    for (const auto& entry : this->getAdj()) {
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

void Graph::addNode(Node node){
    nodes.push_back(node);
}

const std::vector<Node> &Graph::getNodes() const {
    return nodes;
}

void Graph::setNodes(const std::vector<Node> &nodes) {
    Graph::nodes = nodes;
}

void Graph::printNodes() const {
    for(auto node : nodes){
        std::cout << std::setprecision(14) << std::fixed << node.getId() << " ->  x: " << node.getX() << "  y: " << node.getY() << std::endl;
    }
}
