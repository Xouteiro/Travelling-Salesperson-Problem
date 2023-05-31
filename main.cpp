#include "src/AuxMain.h"
#include "src/Functions.h"
#include <locale>
#include <iostream>
#include <ctime>


int main() {
    int option;
    Graph graph, mst;
    string file, nodesFile;
    size_t separator;
    double cost;
    double elapsedTime;
    clock_t begin;

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
                begin = clock();
                cost = tspBacktracking(graph);
                elapsedTime = double(clock() - begin) / CLOCKS_PER_SEC;
                cout << setprecision(14) << "Cost: " << cost << "\n";
                cout << fixed << setprecision(6) << "Elapsed time: " << elapsedTime << " seconds\n";
                break;
            case 3:
                file = selectFileStronglyConnected();

                separator = file.find('|');
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

                begin = clock();
                cost = tspTriangularAppHeuristic(graph);
                elapsedTime = double(clock() - begin) / CLOCKS_PER_SEC;
                cout << setprecision(14) << "Cost: " << cost << "\n";
                cout << fixed << setprecision(6) << "Elapsed time: " << elapsedTime << " seconds\n";
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