/**
 * @file Node.cpp
 * @author Matej Hanke (HAN0390@vsb.cz)
 */
#include "Node.hpp"

/**
 * @brief Default constructor to construct a new Node:: Node object
 */
Node::Node(){
    this->character = 'N';
    this->id = -1;
    this->x = -1;
    this->y = -1;
    this->elevation = -1;
    this->color = 0; // 0 - not visited / 1 - visited / 2 - completed
}

/**
 * @brief Construct a new Node:: Node object
 * 
 * @param character 
 * @param id 
 * @param x 
 * @param y 
 * @param elevation 
 */
Node::Node(char character, int id, int x, int y, int elevation){
    this->character = character;
    this->id = id;
    this->x = x;
    this->y = y;
    this->elevation = elevation;
    this->color = 0;
}

/**
 * @brief Helping method to print all valid neighbors of each node
 */
void Node::printNeighborsIDs(){
    for (auto neighborId : this->neighborsIDs) {
        cout << neighborId << ", ";
    }
    cout << endl;
}