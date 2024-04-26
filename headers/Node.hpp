#pragma once

#include <vector>
#include <iostream>
#include <fstream>
#include <queue>
#include <climits>
using namespace std;

class Node {
public:
    int id;
    int x, y;
    int elevation;
    vector<int> neighborsIDs;

    Node();
    Node(int id, int x, int y, int elevation);
    void printNeighborsIDs();
};
