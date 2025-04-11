#include "linkedList.h"
namespace graph{
//add the implementation of the LinkedList class here
//constructor implementation:
LinkedList::LinkedList() : head(nullptr) {}
//destructor implementation: moving to the next node in the 
//list and then deleting the prevoius one using pointer to it.
LinkedList::~LinkedList() {
    Node* curr = head;
    while (curr != nullptr) {
        Node* nextNode = curr->next;
        delete curr;
        curr = nextNode;
    }
}
void LinkedList::addNode(int vertex , int weight){
    Node* newN = new Node(vertex , weight);
    //case one : list is empty or the vertex is smaller that the first node.
    if(head == nullptr|| head-> vertex > vertex ){
        newN->next = head;
        head = newN;
        return;
    }
    //case two: this current edge is exists so updating the weight.
    Node* curr = head;
    if(curr->vertex == vertex){
        curr->weight = weight;
        delete newN;
        return;
    }
    //finding the right place to insert the new node.
    while(curr->next != nullptr && curr->next->vertex < vertex){
        curr = curr->next;
    }
    //case three: the vertex is already exists in the list.
    if(curr->next != nullptr && curr->next->vertex == vertex){
        curr->next->weight = weight;
        delete newN;
        return;
    } 
    //the vertex is not exists in the list so adding it.
    newN->next = curr->next;
    curr->next = newN;
    
}
//if we remove the node return true else false.
bool LinkedList::removeNode(int vertex){
    //handeling if the list is empty, the node isnt exists.
    if(head == nullptr){
        return false;
    }
    //if the node is the head.
    if(head->vertex == vertex){
        Node* temp = head;
        head = head->next;
        delete temp;
        return true; // node removed successfully.
    }
    //searrching for the node and then removing it.
    Node* curr = head;
    while(curr->next != nullptr && curr->next->vertex != vertex){
        curr = curr->next;
    }
    //if we have found it.
    if(curr->next != nullptr){
        Node* temp = curr->next;
        curr->next = curr->next->next;
        delete temp;
        return true; // node removed successfully.
    }
    return false; // node not found so it was not removed.
}
//displaying the list.
void LinkedList::displayList() const {
    Node * curr = head;
    while (curr != nullptr) {
        std::cout << "[" << curr->vertex << ", " << curr->weight << "] ";
        curr = curr->next;
    }
    
}

//checking if the vertex is in the list.
bool LinkedList::hasVertex(int vertex) const {
    Node* curr = head;
    while (curr != nullptr) {
        if (curr->vertex == vertex) {
            return true; 
        }
        curr = curr->next; // moving the pointer to the next node.
    }
    return false; 
}
//clearing the list.
void LinkedList::clear() {
    Node* curr = head;
    while (curr != nullptr) {
        Node* nextNode = curr->next;
        //free the memory of the current node and then updating it.
        delete curr;
        curr = nextNode;
    }
    head = nullptr; 
}
}


    
