#include <string>
#include "Graph.hpp"

int main(int argc, char const *argv[]) {
    ifstream file(argv[1]);
    if (!file.is_open()) {
        cout << "Error: file couldn't be opened" << endl;
    }

    int rows, cols;
    file >> rows >> cols;
    
    vector<Node*> nodes;
    string line;
    long id = 0;
    int j = 0;

    while (!file.eof()) {
        file >> line;
        for (int i = 0; i < cols; i++) {
            Node* node = new Node();
            node->id = id++;
            node->x = i;
            node->y = j;
            if (line[i] != 'S' && line[i] != 'E') {
                node->elevation = line[i] - 'a';
            } else if (line[i] == 'S') {
                node->elevation = 0;
            } else if(line[i] == 'E') {
                node->elevation = 26;
            }
            nodes.push_back(node);
        }
        j++;
    }
    file.close();

    Graph g(rows, cols, nodes);

    g.initNeighbors();


    for (int i = 0; i < (g.cols*g.rows); i++) {
        g.grid[i]->printNeighborsIDs();
    }
    //cout << g.grid[g.coords(3,3)]->neighbors[0]->x << endl << g.grid[g.coords(3,3)]->neighbors[0]->y << endl;
    

    // // Start and finish vertices
    // Node start = { .value = 'a', .row = 0, .col = 0 };
    // Node finish = { .value = 'f', .row = 3, .col = 2};

    // int shortestPath = graph.findShortestPath(start, finish);
    // if (shortestPath != -1) {
    //     cout << "Shortest path length: " << shortestPath << endl;
    // } else {
    //     cout << "No path found." << endl;
    // }

    return 0;
}