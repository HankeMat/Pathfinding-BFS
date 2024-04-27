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

vector<Node*> Graph::BFS(Node* start, Node* end) {
    queue<Node*> que;
    que.push(start);
    start->color = 1;
    unordered_map<Node*, Node*> parentMap;

    while (!que.empty()) {
        Node* current = que.front();
        que.pop();
        current->color = 2;

        for (auto neighborID : current->neighborsIDs) {
            Node* neighbor = this->grid[neighborID];
            if (neighbor->color == 0) {
                que.push(neighbor);
                neighbor->color = 1;
                parentMap[neighbor] = current;
            }
        }
    }

    vector<Node*> shortestPath;
    Node* currentNode = end;
    while (currentNode != nullptr) {
        shortestPath.push_back(currentNode);
        currentNode = parentMap[currentNode];
    }
    return shortestPath;
}