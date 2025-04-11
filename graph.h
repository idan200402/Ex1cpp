#ifndef GRAPH_H
#define GRAPH_H
#include "linkedList.h"
namespace graph{
class Graph {
private:
    int numOfVertices; 
    LinkedList* adjacencyList; // Array of linkedList , the ith index linkedList represents the ith vertex added.
public:
    Graph(int vertices);
    ~Graph();

//method to implement:
    void addEdge(int source, int dest, int weight);
    void removeEdge(int source, int dest);
    void displayGraph() const;
    int getNumOfVertices() const { return numOfVertices; } 
    const LinkedList* getAdjacencyList() const { return adjacencyList; }

};
}
#endif 
