#pragma once

#include <vector>
using namespace std;

class Node {
public:
    int id;
    int x, y;
    int elevation;
    vector<Node*> neighbors;

    Node();
    Node(int id, int x, int y, int elevation);
};
