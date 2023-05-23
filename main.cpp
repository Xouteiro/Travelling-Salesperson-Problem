#include "src/AuxMain.h"
#include <locale>
#include <iostream>



int main() {
    setlocale(LC_ALL, "pt_PT.UTF-8");
    int option;
    Graph graph;
    string file;
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
            case 0:
                cout << "Bye";
                break;
            default:
                cout << "\nInvalid option. Try again.\n";
        }
    } while (option != 0);
    return 0;
}