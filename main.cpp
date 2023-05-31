#include "src/AuxMain.h"
#include "src/Functions.h"
#include <locale>
#include <iostream>


int main() {
    int option;
    Graph graph, mst;
    string file, nodesFile = "";
    size_t separator;
    double cost;
    //readfiles
    do {
        showMenu();
        option = readOption();
        switch (option) {
            case 1:
                file = selectFile();
                graph = file.empty() ? Graph() : createGraph(file);
                if(graph.getAdj().empty()) {
                    cout << "Invalid file\n";
                    break;
                }
                graph.printGraph();
                break;
            case 2:
                file = selectFile();
                graph = file.empty() ? Graph() : createGraph(file);
                if(graph.getAdj().empty()) {
                    cout << "Invalid file\n";
                    break;
                }
                cost = tspBacktracking(graph);
                cout << fixed << "Cost: " << cost << "\n";
                break;
            case 3:
                file = selectFileStronglyConnected();
                separator = file.find('|');
                cout << separator << endl;
                if(separator < string::npos){
                    nodesFile = file.substr(separator+1);
                    file = file.substr(0, separator);
                }

                graph = file.empty() ? Graph() : createGraph(file);
                if(!nodesFile.empty()) addNodesToGraph(graph, nodesFile);

                if(graph.getAdj().empty()) {
                    cout << "Invalid file\n";
                    break;
                }
                graph.printNodes();
                break;
                cost = tspTriangularAppHeuristic(graph);
                cout << fixed << "Cost: " << cost << "\n";
                break;
            case 0:
                cout << "Bye";
                break;
            default:
                cout << "\nInvalid option. Try again.\n";
        }
    } while (option != 0);
    return 0;
}