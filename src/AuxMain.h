#ifndef RAILWAYMANAGER_AUXMAIN_H
#define RAILWAYMANAGER_AUXMAIN_H


#include "Graph.h"
#include <iostream>

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


#endif