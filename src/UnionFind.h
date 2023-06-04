#ifndef PROJ2_UNIONFIND_H
#define PROJ2_UNIONFIND_H

#include <vector>

/**
 * @brief This class is used in the kruskalMST function to check if adding an edge to the MST will create a cycle.
 */
class UnionFind {
private:
    std::vector<int> parent;
    std::vector<int> rank;
public:
    /**
     * Constructor for the UnionFind class.
     * @param size size of the graph
     */
    explicit UnionFind(int size);

    /**
     * Finds the root of the tree that contains the node x.
     * @param x node to be analyzed
     * @return root of the tree that contains the node x
     */
    int find(int x);

    /**
     * Unites the trees that contain the nodes x and y.
     * @param x node to be analyzed
     * @param y node to be analyzed
     */
    void unite(int x, int y);
};


#endif
