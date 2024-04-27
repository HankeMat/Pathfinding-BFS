#pragma once
#include "Node.hpp"

class Graph {
public:
    int rows, cols;
    vector<Node*> grid;

    Graph(int rows, int cols, vector<Node*> nodes);
    int coords(int x, int y);
    bool isValid(Node* node);
    bool checkElevation(Node* current, Node* neighbor);
    void initNeighbors();
    vector<Node*> BFS(Node* start, Node* end);
};