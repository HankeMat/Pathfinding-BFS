#include "Graph.hpp"
#include "Node.hpp"

Graph::Graph(int rows, int cols, vector<Node*> nodes) {
    this->rows = rows;
    this->cols = cols;
    this->grid = nodes;
}

int Graph::coords(int x, int y){
    return (y * this->cols) + x;
}

// bool Graph::isValid(Node* node){
//     if (node->x >= 0 && node->x < this->cols && node->y >= 0 && node->y < this->rows) {
//         return true;
//     }
//     return false;
// }

bool Graph::checkElevation(Node* current, Node* neighbor){
    if (current->elevation == neighbor->elevation || current->elevation + 1 == neighbor->elevation) {
        return true;
    }
    return false;
}

void Graph::initNeighbors(){
    for (int i = 0; i < (this->cols*this->rows); i++) {
        // Upper neighbor
        if ((i - this->cols) >= 0 && this->checkElevation(this->grid[i], this->grid[i - this->cols])) {
            this->grid[i]->neighborsIDs.push_back(this->grid[i - this->cols]->id);
        }
        // Right neighbor
        if ((i + 1) % this->cols != 0 && this->checkElevation(this->grid[i], this->grid[i + 1])) {
            this->grid[i]->neighborsIDs.push_back(this->grid[i + 1]->id);
        }
        // Bottom neighbor
        if ((i + this->cols) < (this->cols*this->rows) && this->checkElevation(this->grid[i], this->grid[i + this->cols])) {
            this->grid[i]->neighborsIDs.push_back(this->grid[i + this->cols]->id);
        }
        // Left neighbor
        if (i % this->cols != 0  && this->checkElevation(this->grid[i], this->grid[i - 1])) {
            this->grid[i]->neighborsIDs.push_back(this->grid[i - 1]->id);
        }
    }
}

// int Graph::findShortestPath(Node start, Node finish) {
//     vector<vector<bool>> visited(this->grid.size(), vector<bool>(this->grid[0].size(), false));
//     queue<pair<Node, int>> q;
//     q.push({start, 0});
//     visited[start.row][start.col] = true;

//     while (!q.empty()) {
//         Node current = q.front().first;
//         int distance = q.front().second;
//         q.pop();

//         if (current.row == finish.row && current.col == finish.col) {
//             return distance;
//         }

//         // Explore neighbors
//         for (int dx = -1; dx <= 1; ++dx) {
//             for (int dy = -1; dy <= 1; ++dy) {
//                 if (dx == 0 && dy == 0) continue;
//                 int newRow = current.row + dx;
//                 int newCol = current.col + dy;
//                 if (newRow >= 0 && newRow < this->grid.size() && newCol >= 0 && newCol < this->grid[newRow].size()) {
//                     if (!visited[newRow][newCol]) {
//                         q.push({this->grid[newRow][newCol], distance + 1});
//                         visited[newRow][newCol] = true;
//                     }
//                 }
//             }
//         }
//     }

//     // If no path found
//     return -1;
// }