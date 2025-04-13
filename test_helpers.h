//idan.shumski@gmail.com

#ifndef TEST_HELPERS_H
#define TEST_HELPERS_H
#include "graph.h"
//this file contains helper functions to test the algorithms , it prevents code duplication.
namespace graph {
//helper function for bfs and dfs to check if an edge exists in the graph.
bool edgeExists(graph::Graph &g, int src, int dest) {
    Node* neighbours = g.getAdjacencyList()[src].getHead();
    while (neighbours != nullptr) {
        if (neighbours->vertex == dest) {
            return true;
        }
        neighbours = neighbours->next;
    }
    return false;
}

//helper function for dijkstra to check if an edge exists in the graph and return its weight.
int findEdgeWeight(graph::Graph &g, int src, int dest) {
    Node* neighbours = g.getAdjacencyList()[src].getHead();
    while (neighbours != nullptr) {
        if (neighbours->vertex == dest) {
            return neighbours->weight;
        }
        neighbours = neighbours->next;
    }
    return -1; // edge not found , use this case to check if the edge is not in the graph.
}

//helper function for kruskal and prim to check a total weight of the graph (hopefully the minimum spanning tree).
int calculateTotalWeight(graph::Graph &g) {
    int totalWeight = 0;
    int vertices = g.getNumOfVertices();
    bool* edgeCount = new bool[vertices * vertices];
    //initializing the edgeCount array to false since we have not visited any edges yet.
    for (int i = 0; i < vertices * vertices; i++) {
        edgeCount[i] = false;
    }
    for(int i = 0; i < vertices; i++) {
        Node* neighbours = g.getAdjacencyList()[i].getHead();
        while (neighbours != nullptr) {
            int neighbour = neighbours->vertex;
            //with compering id values we can check if the edge is already added.
            if (i < neighbour && !edgeCount[i * vertices + neighbour]) {
                totalWeight += neighbours->weight;
                edgeCount[i * vertices + neighbour] = true;
            }
            neighbours = neighbours->next;
        }
    }
    delete[] edgeCount;
    return totalWeight;
    
}
}
#endif 
