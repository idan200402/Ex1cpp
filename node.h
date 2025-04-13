//idan.shumski@gmail.com

#ifndef NODE_H
#define NODE_H
namespace graph{
// creating a basic struct to hold the vertex and weight of the new edge
// in the adjacency list.
struct Node{
    int vertex;
    int weight;
    Node* next;
    Node(int vertex, int weight) : vertex(vertex), weight(weight), next(nullptr) {}
};
}
#endif 