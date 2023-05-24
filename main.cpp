#include "src/AuxMain.h"
#include "src/Functions.h"
#include <locale>
#include <iostream>



int main() {
    setlocale(LC_ALL, "pt_PT.UTF-8");
    int option;
    Graph graph;
    string file;
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
                printGraph(graph);
                break;
            case 2:
                file = selectFile();
                graph = file.empty() ? Graph() : createGraph(file);
                if(graph.getAdj().empty()) {
                    cout << "Invalid file\n";
                    break;
                }
                cost = tspBacktracking(graph);
                cout << "Cost: " << cost << "\n";
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