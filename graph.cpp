#include "graph.h"
namespace graph{
//constructor implementation:
Graph:: Graph(int vertices) : numOfVertices(vertices) {
    adjacencyList = new LinkedList[vertices]; 
}
//destructor implementation:
Graph::~Graph() {
    delete[] adjacencyList; 
}

//adding an edge to the Graph implementation.
void Graph::addEdge(int s , int dest , int weight){
    if(s < 0 || s >= numOfVertices || dest < 0 || dest >= numOfVertices){
        std::cout << "Invalid edge." << std::endl;
        return;
    }
    //if it valid so adding each node to the other adjacency list.
    adjacencyList[s].addNode(dest , weight);
    adjacencyList[dest].addNode(s , weight);
}
void Graph::removeEdge(int s  , int dest){
    //checking if this egde is possible.
    if(s < 0 || s >= numOfVertices || dest < 0 || dest >= numOfVertices){
        std::cout << "Invalid edge." << std::endl;
        return;
    }
    //since it possible to have it we tryung to remove it.
    bool r1 = adjacencyList[s].removeNode(dest);
    bool r2 = adjacencyList[dest].removeNode(s);
    if(r1 && r2){
        std::cout << "Edge removed successfully." << std::endl;
    }else{
        std::cout << "Edge not found." << std::endl;
    }
}

//displaying the Graph.
void Graph::displayGraph() const{
    for(int i = 0  ; i<numOfVertices ; i++){
        std::cout << "Vertex " << i << " has neighbors: ";
        adjacencyList[i].displayList();
        std::cout << std::endl;
    }
}
}



