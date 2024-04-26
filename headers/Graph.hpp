#pragma once

#include <iostream>
#include <fstream>
#include <queue>
#include <climits>
#include "Node.hpp"

using namespace std;

class Graph {
public:
    int rows, cols;
    vector<Node*> grid;

    Graph(int rows, int cols, vector<Node*> nodes);
    int coords(int x, int y);
    bool isValid(Node* node);
    void initNeighbors();
    
    // int findShortestPath(Node start, Node finish);
};