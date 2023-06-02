#ifndef PROJ2_UNIONFIND_H
#define PROJ2_UNIONFIND_H

#include <iostream>
#include <vector>

using namespace std;

class UnionFind {
private:
    vector<int> parent;
    vector<int> rank;

public:
    UnionFind(int size);

    int find(int x);

    void unite(int x, int y);
};


#endif
