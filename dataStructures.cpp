#include "dataStructures.h"
#include <iostream>

namespace graph{

//implementing the Queue class:
//constructor implementation:
Queue::Queue() : front(nullptr), back(nullptr) {}
//destructor implementation:
Queue::~Queue() {
    while (!isEmpty()) {
        dequeue(); // dequeue all elements to free memory.
    }
}
void Queue::enqueue(int value){
    Node* newNode = new Node(value);
    if (isEmpty()) {
        //if the queue is empty setting both to the new node.
        front = back = newNode; 
    } else {
        //if the queue is not empty adding the new node to the back while preserving the order.
        back->next = newNode;
        back = newNode;
    }
}
int Queue::dequeue(){
    if(isEmpty()){
        std::cout << "The queue is empty. no values to dequeue" << std::endl;
        return -1; 
    }
    Node* temp = front; // saving the pointer to the front node.
    int value = temp->data;
    front = front->next; 
    //if the queue has had one element:
    if(front == nullptr){
        back = nullptr; 
    }
    //dealeting the front nodes memory.
    delete temp; 
    return value; // returning the dequeued value.
}

bool Queue::isEmpty() const{
    return front == nullptr; 
}

//implementing the PriorityQueue class:
//constructor implementation:
PriorityQueue::PriorityQueue() : head(nullptr) {}
//destructor implementation:
PriorityQueue::~PriorityQueue() {
    while (!isEmpty()) {
        pop(); // pop all elements to free memory.
    }
}
void PriorityQueue::push(int value, int priority){
    Node* newNode = new Node(value, priority);
    //the queue is empty or the curr node has the highest priority.
    if(isEmpty() || head->priority > priority){
        newNode->next = head;
        head = newNode;
    }
    else{
        Node* curr = head;
        while(curr->next != nullptr &&curr->next->priority<=priority){
            curr = curr->next;
        }
        newNode->next = curr -> next;
        curr->next  = newNode;

    }
}

int PriorityQueue::pop(){
    if(isEmpty()){
        std::cout<<"The P queue is empty"<<std::endl;
        return -1;
    }
    Node* temp  = head;
    int v = temp->val;
    head = head->next;
    //free the pointer address.
    delete temp;
    return v; // returning the vertex if the process is  succsecful.
}
bool PriorityQueue::isEmpty() const{
    return head == nullptr;
}
bool PriorityQueue::contains(int vertex) const{
    Node* curr = head;
    while(curr!=nullptr){
        if(curr->val == vertex){
            return true;
        }
        curr = curr->next;
    }
    return false;
}

void PriorityQueue::decreasePriority(int val , int newPriority){
    Node* curr = head;
    Node* prev = nullptr;
    if(!contains(val)){ return; }
    while(curr!= nullptr && curr->val!=val){
        prev = curr;
        curr = curr->next;    
    }
    if(curr == nullptr){
        return;
    }
    //in case the current position from the start is it.
    if(prev == nullptr){
        head = curr->next;
    }
    else{
        prev->next = curr->next;
    }
    //inserting the node in the new position.
    push(val , newPriority);
}
//implementing the UnionFind class:
UnionFind::UnionFind(int n): size(n){
    // setting the arrays for both parent and rank.
    parent = new int[n];
    rank = new int[n];
    //initially each node is its own parent and rank is 0.
    for(int i = 0; i < n; i++){
        parent[i] = i;
        rank[i] = 0; 
    }
}
//destructor implementation:
UnionFind::~UnionFind(){
    delete[] parent; 
    delete[] rank;
}
int UnionFind::find(int x){
    if(parent[x] != x){
        //path compression: making the tree flat by pointing each node to its root.
        //this will speed up future find operations.
        parent[x] = find(parent[x]); 
    }
    return parent[x];    
}
void UnionFind::unionSets(int x, int y){
    int superParentX = find(x);
    int superParentY = find(y);
    //in case they have the same ancestry.
    if(superParentX == superParentY){
        return; 
    }
    //without loss of generality if superParentX is the smaller one.
    //union by rank: attach the smaller tree under the larger tree.
    //this will keep the tree as flat as possible.
    if(rank[superParentX] < rank[superParentY]){
        parent[superParentX] = superParentY; 
    }
    else if(rank[superParentX] > rank[superParentY]){
        parent[superParentY] = superParentX; 
    }
    else{
        parent[superParentY] = superParentX;
        rank[superParentX]++;
    }
}
}

