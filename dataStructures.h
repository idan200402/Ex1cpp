#ifndef DATASTRUCTURES_H
#define DATASTRUCTURES_H
//This header file containes the declarations of the DS we need 
// in order to implement the graph class.
namespace graph{
class Queue{
private:
    struct Node{
        int data;
        Node* next;
        Node(int val) : data(val), next(nullptr) {}
    };
    Node* front;
    Node* back;
public:
    Queue();
    ~Queue();
    void enqueue(int val);
    int dequeue();
    bool isEmpty() const;


};

class PriorityQueue{
private:
    struct Node{
        int val;
        int priority;
        Node* next;
        Node(int val, int prio) : data(val), priority(prio), next(nullptr) {}
    };
    Node* head;

public:
    PriorityQueue();
    ~PriorityQueue();
    void push(int val, int priority);
    int pop();
    bool contains(int val) const;
    bool isEmpty() const;
    void decreasePriority(int val, int newP);



};

class UnionFind{
private:
    int* parent;
    int* rank;
    int size;
public:
    UnionFind(int n);
    ~UnionFind();
    int find(int x);
    void union(int x, int y);

};


struct Edge{
    int src;
    int dest;
    int weight;
    Edge(int s, int d, int w) : src(s), dest(d), weight(w) {}
    
    //overloading < operator to compare between any two edges elegantly.
    //for kruskal algo.
    bool operator<(const Edge& other) const {
        return weight < other.weight; 
    }
};

}




#endif

