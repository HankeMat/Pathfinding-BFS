#pragma once

#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

struct Vertex {
    char value;
    int row;
    int col;
};

class Graph {
private:
    vector<vector<Vertex>> grid;
public:
    Graph(vector<vector<char>>& inputGrid);

    void initializeEdges();
    int findShortestPath(Vertex start, Vertex finish);
};