#include "Graph.hpp"

int main() {
    // Example usage
    vector<vector<char>> inputGrid = {
        {'a', 'b', 'c'},
        {'d', 'a', 'd'},
        {'h', 'g', 'e'},
        {'j', 'i', 'f'}
    };

    Graph graph(inputGrid);

    // Start and finish vertices
    Vertex start = { .value = 'a', .row = 0, .col = 0 };
    Vertex finish = { .value = 'f', .row = 3, .col = 2};

    int shortestPath = graph.findShortestPath(start, finish);
    if (shortestPath != -1) {
        cout << "Shortest path length: " << shortestPath << endl;
    } else {
        cout << "No path found." << endl;
    }

    return 0;
}
