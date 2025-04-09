#include "graph.h"
#include <iostream>

int main() {
    // Create a graph with 5 vertices
    graph::Graph graph(5);

    // Add edges to the graph
    graph.addEdge(0, 1, 10);
    graph.addEdge(0, 2, 20);
    graph.addEdge(1, 2, 30);
    graph.addEdge(1, 3, 40);
    graph.addEdge(2, 4, 50);

    // Display the graph
    std::cout << "Graph adjacency list  (for every pair the right val is vertex id and the left val is the edge weight from the main vertex):" << std::endl;
    graph.displayGraph();

    // Remove an edge
    graph.removeEdge(1, 2);

    // Display the graph after removing an edge
    std::cout << "Graph after removing edge (1, 2):" << std::endl;
    graph.displayGraph();

    return 0;
}