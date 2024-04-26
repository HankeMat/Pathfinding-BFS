#include "Node.hpp"

Node::Node(){
    this->id = -1;
    this->x = -1;
    this->y = -1;
    this->elevation = -1;
}

Node::Node(int id, int x, int y, int elevation){
    this->id = id;
    this->x = x;
    this->y = y;
    this->elevation = elevation;
}