#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>
#include "node.h" // Include the Node struct header file.
namespace graph{
class LinkedList {
private:
    Node* head; // Pointer to the head of the linked list.

public:
// Constructor and Destructor signatures.
    LinkedList();
    ~LinkedList();
// methods to manage the linked list (signatures only).
    void addNode(int vertex, int weight); 
    bool removeNode(int vertex); 
    void displayList() const; 
    bool hasVertex(int vertex) const;
    Node* getHead() const { return head; } 
};
}   
#endif 