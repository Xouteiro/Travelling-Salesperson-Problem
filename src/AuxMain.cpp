#include "AuxMain.h"


void showMenu() {
    cout << "\n1) Print Graph\n"; //Depois muda-se e depois mete-se o print do grafo diferente
    cout << "\n2) TSP Backtracking\n";
    cout << "\n3) TSP Triangular Approximation Heuristic\n";
    cout << "\n4) TSP Nearest Neighbor Heuristic\n";
    cout << "\n0) Exit\n";
    cout << "\nChoose an option: ";
}

void showFileOptions(){
    cout << "\nToy Graphs:\n";
    cout << "\n\t11) Shipping\n";
    cout << "\t12) Stadiums\n";
    cout << "\t13) Tourism\n";
    cout << "\nExtra Fully Connected Graphs:\n";
    cout << "\n\t21) 25 edges\n";
    cout << "\t22) 50 edges\n";
    cout << "\t23) 75 edges\n";
    cout << "\t24) 100 edges\n";
    cout << "\t25) 200 edges\n";
    cout << "\t26) 300 edges\n";
    cout << "\t27) 400 edges\n";
    cout << "\t28) 500 edges\n";
    cout << "\t29) 600 edges\n";
    cout << "\t210) 700 edges\n";
    cout << "\t211) 800 edges\n";
    cout << "\t212) 900 edges\n";
    cout << "\nReal World Graphs:\n";
    cout << "\n\t31) Graph 1\n";
    cout << "\t32) Graph 2\n";
    cout << "\t33) Graph 3\n";
    cout << "\n0) Exit\n";
    cout << "\nChoose an option: ";
}

void showFileOptionsStronglyConnected(){
    cout << "\nToy Graphs:\n";
    cout << "\n\t12) Stadiums\n";
    cout << "\t13) Tourism\n";
    cout << "\nExtra Fully Connected Graphs:\n";
    cout << "\n\t21) 25 edges\n";
    cout << "\t22) 50 edges\n";
    cout << "\t23) 75 edges\n";
    cout << "\t24) 100 edges\n";
    cout << "\t25) 200 edges\n";
    cout << "\t26) 300 edges\n";
    cout << "\t27) 400 edges\n";
    cout << "\t28) 500 edges\n";
    cout << "\t29) 600 edges\n";
    cout << "\t210) 700 edges\n";
    cout << "\t211) 800 edges\n";
    cout << "\t212) 900 edges\n";
    cout << "\nReal World Graphs:\n";
    cout << "\n\t31) Graph 1\n";
    cout << "\t32) Graph 2\n";
    cout << "\t33) Graph 3\n";
    cout << "\n0) Exit\n";
    cout << "\nChoose an option: ";
}

string selectFile(){
    int option;
    showFileOptions();
    option = readOption();
    switch (option) {
        case 0:
            break;
        case 11:
            return "../data/Toy-Graphs/shipping.csv";
        case 12:
            return "../data/Toy-Graphs/stadiums.csv";
        case 13:
            return "../data/Toy-Graphs/tourism.csv";
        case 21:
            return "../data/Extra_Fully_Connected_Graphs/edges_25.csv";
        case 22:
            return "../data/Extra_Fully_Connected_Graphs/edges_50.csv";
        case 23:
            return "../data/Extra_Fully_Connected_Graphs/edges_75.csv";
        case 24:
            return "../data/Extra_Fully_Connected_Graphs/edges_100.csv";
        case 25:
            return "../data/Extra_Fully_Connected_Graphs/edges_200.csv";
        case 26:
            return "../data/Extra_Fully_Connected_Graphs/edges_300.csv";
        case 27:
            return "../data/Extra_Fully_Connected_Graphs/edges_400.csv";
        case 28:
            return "../data/Extra_Fully_Connected_Graphs/edges_500.csv";
        case 29:
            return "../data/Extra_Fully_Connected_Graphs/edges_600.csv";
        case 210:
            return "../data/Extra_Fully_Connected_Graphs/edges_700.csv";
        case 211:
            return "../data/Extra_Fully_Connected_Graphs/edges_800.csv";
        case 212:
            return "../data/Extra_Fully_Connected_Graphs/edges_900.csv";
        case 31:
            return "../data/Real-World Graphs/graph1/edges.csv";
        case 32:
            return "../data/Real_World Graphs/graph2/edges.csv";
        case 33:
            return "../data/Real_World Graphs/graph3/edges.csv";
        default:
            return {};
    }
    return {};
}

string selectFileStronglyConnected(){
    int option;
    showFileOptionsStronglyConnected();
    option = readOption();
    switch (option) {
        case 0:
            break;
        case 12:
            return "../data/Toy-Graphs/stadiums.csv";
        case 13:
            return "../data/Toy-Graphs/tourism.csv";
        case 21:
            return "../data/Extra_Fully_Connected_Graphs/edges_25.csv";
        case 22:
            return "../data/Extra_Fully_Connected_Graphs/edges_50.csv";
        case 23:
            return "../data/Extra_Fully_Connected_Graphs/edges_75.csv";
        case 24:
            return "../data/Extra_Fully_Connected_Graphs/edges_100.csv";
        case 25:
            return "../data/Extra_Fully_Connected_Graphs/edges_200.csv";
        case 26:
            return "../data/Extra_Fully_Connected_Graphs/edges_300.csv";
        case 27:
            return "../data/Extra_Fully_Connected_Graphs/edges_400.csv";
        case 28:
            return "../data/Extra_Fully_Connected_Graphs/edges_500.csv";
        case 29:
            return "../data/Extra_Fully_Connected_Graphs/edges_600.csv";
        case 210:
            return "../data/Extra_Fully_Connected_Graphs/edges_700.csv";
        case 211:
            return "../data/Extra_Fully_Connected_Graphs/edges_800.csv";
        case 212:
            return "../data/Extra_Fully_Connected_Graphs/edges_900.csv";
        case 31:
            return "../data/Real-World Graphs/graph1/edges.csv|../data/Real-World Graphs/graph1/nodes.csv";
        case 32:
            return "../data/Real-World Graphs/graph2/edges.csv|../data/Real-World Graphs/graph2/nodes.csv";
        case 33:
            return "../data/Real-World Graphs/graph3/edges.csv|../data/Real-World Graphs/graph3/nodes.csv";
        default:
            return {};
    }
    return {};
}

int readOption() {
    int option;

    if(!(cin >> option)) {
        cin.clear();
        cin.ignore(1000, '\n');
        return 100;
    }
    return option;
}

Graph createGraph(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cout << "Error on opening: " << filename << "\n";
        return {};
    }

    std::string line;
    std::getline(file, line); // Skip the header line

    Graph graph;

    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string token;
        std::vector<std::string> tokens;

        while (std::getline(ss, token, ',')) {
            tokens.push_back(token);
        }

        if (tokens.size() < 3) {
            std::cout << "Invalid line: " << line << "\n";
            continue;
        }

        int source = std::stoi(tokens[0]);
        int destination = std::stoi(tokens[1]);
        double distance = std::stod(tokens[2]);

        graph.addEdge(source, destination, distance);
    }

    return graph;
}

void addNodesToGraph(Graph& graph, const string& filename){
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cout << "Error on opening: " << filename << "\n";
        return;
    }

    std::string line;
    std::getline(file, line); // Skip the header line

    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string token;
        std::vector<std::string> tokens;

        while (std::getline(ss, token, ',')) {
            tokens.push_back(token);
        }

        if (tokens.size() < 3) {
            std::cout << "Invalid line: " << line << "\n";
            continue;
        }

        int id = std::stoi(tokens[0]);
        double x = std::stod(tokens[1]);
        double y = std::stod(tokens[2]);

        Node node = Node(id, x, y);
        graph.addNode(node);
    }
}