/**
 * @file Node.hpp
 * @author Matej Hanke (HAN0390@vsb.cz)
 */
#pragma once

#include <vector>
#include <iostream>
#include <fstream>
#include <queue>
#include <climits>
#include <unordered_map>
#include <string>
#include <algorithm>
using namespace std;

/**
 * @brief A class to represent each Node
 * @public char character, int id, int x, int y, int elevation, vector<int> neighborsIDs, int color
 */
class Node {
public:
    char character;
    int id;
    int x, y;
    int elevation;
    vector<int> neighborsIDs;
    int color;

    Node();
    Node(char character, int id, int x, int y, int elevation);
    void printNeighborsIDs();
};
