#ifndef RAILWAYMANAGER_AUXMAIN_H
#define RAILWAYMANAGER_AUXMAIN_H


#include "Graph.h"

using namespace std;


/**
 * @brief Shows the main menu
 */
void showMenu();

/**
 * @brief Shows the file options
 */
void showFileOptions();

/**
 * @brief Shows the file options for strongly connected graphs
 */
void showFileOptionsStronglyConnected();

string selectFile();

string selectFileStronglyConnected();

/**
 * @brief Reads the option chosen by the user
 * @return The option chosen by the user
 */
int readOption();

/**
 * @brief Reads the input of the user
 * @return The input of the user
 */
string readInput();


/**
 * @brief Creates a graph from a file
 * @param filename The name of the file
 * @return the graph that represents the data in the file
 */
Graph createGraph(const std::string& filename);

/**
 * @brief Adds nodes to a graph from a file
 * @param graph The graph to which the nodes will be added
 * @param filename The name of the file
 */
void addNodesToGraph(Graph& graph, const string& filename);

#endif