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
    Node* startNode = new Node();
    Node* endNode = new Node();
    while (!file.eof()) {
        file >> line;
        for (int i = 0; i < cols; i++) {
            Node* node = new Node();
            node->character = line[i];
            node->id = id++;
            node->x = i;
            node->y = j;
            if (line[i] != 'S' && line[i] != 'E') {
                node->elevation = line[i] - 'a';
            } else if (line[i] == 'S') {
                node->elevation = -1;
                startNode = node;
            } else if(line[i] == 'E') {
                node->elevation = 26;
                endNode = node;
            }
            nodes.push_back(node);
        }
        j++;
    }
    file.close();

    Graph g(rows, cols, nodes);
    g.initNeighbors();
    vector<Node*> shortestPath = g.BFS(startNode, endNode);
    reverse(shortestPath.begin(), shortestPath.end());
    if (shortestPath.size()-1 == 0) {
        cout << "There is no possible path to go through" << endl;
    } else {
        cout << "Path: ";
        for (auto node : shortestPath) {
            if (node->character == 'E') {
                cout << node->character;
                break;
            } else 
                cout << node->character << "-";
        }
        cout << endl << "Shortest path length: " << shortestPath.size()-1 << endl;
    }
    return 0;
}