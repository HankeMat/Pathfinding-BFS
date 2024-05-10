/**
 * @file Graph.hpp
 * @author Matej Hanke (HAN0390@vsb.cz)
 */
#pragma once
#include "Node.hpp"

/**
 * @brief A class representing the graph 
 * @public int rows, int cols, vector<Node*> grid ... and methods
 */
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