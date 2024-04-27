#include "Node.hpp"

Node::Node(){
    this->character = 'N';
    this->id = -1;
    this->x = -1;
    this->y = -1;
    this->elevation = -1;
    this->color = 0; // 0 - not visited / 1 - visited / 2 - completed
}

Node::Node(char character, int id, int x, int y, int elevation){
    this->character = character;
    this->id = id;
    this->x = x;
    this->y = y;
    this->elevation = elevation;
    this->color = 0;
}

void Node::printNeighborsIDs(){
    for (auto neighborId : this->neighborsIDs) {
        cout << neighborId << ", ";
    }
    cout << endl;
}