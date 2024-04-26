#include "Graph.hpp"

Graph::Graph(vector<vector<char>>& inputGrid) {
    // Initialize the grid of vertices
    for (int i = 0; i < inputGrid.size(); ++i) {
        vector<Vertex> row;
        for (int j = 0; j < inputGrid[i].size(); ++j) {
            Vertex v;
            v.value = inputGrid[i][j];
            v.row = i;
            v.col = j;
            row.push_back(v);
        }
        grid.push_back(row);
    }
    // Initialize the edges based on the adjacency rules
    initializeEdges();
}

void Graph::initializeEdges() {
    for (int i = 0; i < this->grid.size(); ++i) {
        for (int j = 0; j < this->grid[i].size(); ++j) {
            char currentValue = this->grid[i][j].value;
            for (int dx = -1; dx <= 1; ++dx) {
                for (int dy = -1; dy <= 1; ++dy) {
                    if (dx == 0 && dy == 0) continue; // Skip the current vertex
                    int newRow = i + dx;
                    int newCol = j + dy;
                    if (newRow >= 0 && newRow < this->grid.size() && newCol >= 0 && newCol < this->grid[newRow].size()) {
                        char neighborValue = this->grid[newRow][newCol].value;
                        if (neighborValue >= currentValue) {
                            // Add edge from current vertex to neighbor
                            // You can store edges as needed for the BFS algorithm
                        }
                    }
                }
            }
        }
    }
}

int Graph::findShortestPath(Vertex start, Vertex finish) {
    vector<vector<bool>> visited(this->grid.size(), vector<bool>(this->grid[0].size(), false));
    queue<pair<Vertex, int>> q;
    q.push({start, 0});
    visited[start.row][start.col] = true;

    while (!q.empty()) {
        Vertex current = q.front().first;
        int distance = q.front().second;
        q.pop();

        if (current.row == finish.row && current.col == finish.col) {
            return distance;
        }

        // Explore neighbors
        for (int dx = -1; dx <= 1; ++dx) {
            for (int dy = -1; dy <= 1; ++dy) {
                if (dx == 0 && dy == 0) continue;
                int newRow = current.row + dx;
                int newCol = current.col + dy;
                if (newRow >= 0 && newRow < this->grid.size() && newCol >= 0 && newCol < this->grid[newRow].size()) {
                    if (!visited[newRow][newCol]) {
                        q.push({this->grid[newRow][newCol], distance + 1});
                        visited[newRow][newCol] = true;
                    }
                }
            }
        }
    }

    // If no path found
    return -1;
}