#include "algorithms.h"
#include <iostream>
#include "dataStructures.h"
//implementing all the methods declerations.
namespace graph {
Graph* Algorithms::bfs(Graph &g , int source){
    int vertices = g.getNumOfVertices();
    //initializing the graph only with the vertices.
    Graph* bfsTree = new Graph(vertices);
    bool* visited = new bool[vertices]; // visited arr.
    for(int i = 0 ; i < vertices ; i++){
        // setting all to false since we havent visited.
        visited[i] = false; 
    }
    //creating the queue to hold the vertices.
    Queue q; 
    visited[source] = true; // marking the source as visited.
    q.enqueue(source);
    while(!q.isEmpty()){
        int currVisited = q.dequeue(); 
        //now exploring the neighbours of the current vertex.
        Node* neighbours = g.getAdjacencyList()[currVisited].getHead();
        while(neighbours != nullptr){
            int neighbour = neighbours->data;
            if(!visited[neighbour]){
                visited[neighbour] = true;
                q.enqueue(neighbour); 
                bfsTree->addEdge(currVisited , neighbour , neighbours->weight);
            } 
            neighbours = neighbours->next; 
        }

    }
    //freeing the memory.
    delete[] visited; 
    return bfsTree;

}

void Algorithms::dfsHelper(Graph &g , int vertex , bool *visited , Graph *forest){
    //marking the vertex as visited .
    visited[vertex] = true;
    //finding his neighbours. 
    Node* neighbours = g.getAdjacencyList()[vertex].getHead();
    //iterating through the neighbours until the end.
    while(neighbours != nullptr){
        int neighbour = neighbours->data;
        if(!visited[neighbour]){
            //this case is a tree edge.
            forest->addEdge(vertex , neighbour , neighbours->weight);
            //recursively calling the dfsHelper method to visit the neighbour as source.
            dfsHelper(g , neighbour , visited , forest);

        }
        neighbours = neighbours->next;
    }        
}  


Graph* Algorithms::dfs(Graph &g , int source){
    int vertices = g.getNumOfVertices();
    //initializing the graph only with the vertices.
    Graph* dfsTree = new Graph(vertices);
    bool* visited = new bool[vertices]; // visited arr.
    for(int i = 0 ; i < vertices ; i++){
        // setting all to false since we havent visited.
        visited[i] = false; 
    }
    //calling the dfsHelper method to start the dfs process.
    dfsHelper(g , source , visited , dfsTree);
    //freeing the memory.
    delete[] visited; 
    return dfsTree;
}

Graph* Algorithms::dijkstra(Graph &g , int source){
    int vertices = g.getNumOfVertices();
    //initializing the graph only with the vertices.
    Graph* dijkstraTree = new Graph(vertices);
    //creating a distance array to hold the distance from the source to every vertex.
    int* dist = new int(vertices);
    //creating a parent array to hold the parent of each vertex.
    int* parent = new int[vertices];
    //storing the visited vertices.
    bool* visited = new bool[vertices]; 

    for(int i = 0 ; i < vertices ; i++){
        //initializing all entries to false.
        visited[i] = false;
        //initializing the distance to infinity.
        dist[i] = INT_MAX;
        //initializing the parent to -1.
        parent[i] = -1;
    }
    dist[source] = 0; 
    PriorityQueue pQueue;
    //pushing the source vertex to the queue with distance 0.
    pQueue.push(source , 0); 
    while(!pQueue.isEmpty()){
        //vertex with minimum distance.
        int currVertex = pQueue.pop();
        //marking as visited.
        visited[currVertex] = true;
        Node* neighbours = g.getAdjacencyList()[currVertex].getHead();
        while(neighbours != nullptr){
            int neighbour = neighbours->data;
            int weight = neighbours->weight;
            //there there is exist a shorter path to the neighbour under this condition.
            if(!visited[neighbour] && dist[currVertex] != INT_MAX && dist[currVertex] + weight < dist[neighbour]){
                //updating the new distance and parent.
                dist[neighbour] = dist[currVertex] + weight;
                parent[neighbour] = currVertex;
                //pushing the neighbour to the queue with the new distance.
                pQueue.push(neighbour , distance[neighbour]);
            }
            neighbours = neighbours->next;
        }
    }
    //after this iterations ends we have the shortest path from source to all the vertices.
    //now we can create the dijkstra tree by adding the edges from the parent array.
    for(int i = 0 ; i < vertices ; i++){
        if(parent[i] != -1 && i!= source){
            Node* neighbours = g.getAdjacencyList()[i].getHead();
            //iterating through the neighbours to find the weight of the edge.
            int weight = 0;
            while(neighbours != nullptr){
                if(neighbours->data == i){
                    weight = neighbours->weight;
                    break;
                }
                neighbours = neighbours->next;
            }
            dijkstraTree->addEdge(parent[i] , i , weight);
        }
    }
    //freeing the memory we needed to create the dijkstra tree.
    delete[] dist;
    delete[] parent;
    delete[] visited;
    return dijkstraTree;          
}

Graph* Algorithms::prim(Graph &g){
    int vertices = g.getNumOfVertices();
    //initializing the graph only with the vertices.
    Graph* primTree = new Graph(vertices);
    //the minimum edges we'd like to add to the mst
    int* key = new int[vertices];
    int* parent = new int[vertices];
    //what verices are allready in.
    bool* inMST = new bool[vertices];
    for(int i = 0 ; i < vertices ; i++){
        //initializing all entries to false.
        inMST[i] = false;
        //initializing the distance to infinity.
        key[i] = INT_MAX;
        //initializing the parent to -1.
        parent[i] = -1;
    }
    //without loss of generality we can start from the first vertex for simplicity.
    key[0] = 0;
    PriorityQueue pQueue;
    //pushing the first vertex to the queue with distance 0.
    pQueue.push(0 , 0);
    while(!pQueue.isEmpty()){
        //vertex with minimum distance.
        int currVertex = pQueue.pop();
        inMST[currVertex] = true;
        if(parent[currVertex] != -1){
            Node* neighbours = g.getAdjacencyList()[currVertex].getHead();
            int weight = 0;
            //iterating through the neighbours to find the minimum edge weight.
            while(neighbours != nullptr){
                if(neighbours->data == currVertex){
                    weight = neighbours->weight;
                    break;
                }
                neighbours = neighbours->next;
            }
            //adding the minimum edge weight to the mst.
            primTree->addEdge(parent[currVertex] , currVertex , weight);
        }
        Node* neighbours = g.getAdjacencyList()[currVertex].getHead();
        while(neighbours != nullptr){
            int neighbour = neighbours->data;
            int weight = neighbours->weight;
            //there there is exist a shorter path to the neighbour under this condition.
            if(!inMST[neighbour] && weight < key[neighbour]){
                //updating the new distance and parent.
                key[neighbour] = weight;
                parent[neighbour] = currVertex;
                //pushing the neighbour to the queue with the new distance.
                pQueue.push(neighbour , key[neighbour]);
            }
            neighbours = neighbours->next;
        }
    }
    //freeing the memory we needed to create the prim tree.
    delete[] key;
    delete[] parent;
    delete[] inMST;
    return primTree;
} 

//this helper method is important method that used in the kruskal algorithm.
//could make it without it but its the core.
void Algorithms::getAllEdges(Graph &g , Edge* edges , int &edgeCount){
    int vertices = g.getNumOfVertices();
    edgeCount = 0;
    for(int i = 0 ; i < vertices ; i++){
     Node* neighbours = g.getAdjacencyList()[i].getHead();
        while(neighbours != nullptr){
            int neighbour = neighbours->data;
            //checking if the edge is already added with compering their identity.
            if(i < neighbour){
                edges[edgeCount++]= Edge(i , neighbour , neighbours->weight);
            }
            neighbours = neighbours->next;
        }
    }
}
//implementing quick sort algorithm to sort the edges by weight.
//this is a helper method to the kruskal algorithm.
void Algorithms::sortEdges(Edge* edges , int edgeCount){
    for(int i = 0 ; i < edgeCount - 1 ; i++){
        for(int j = 0 ; j < edgeCount - i - 1 ; j++){
            if(edges[j].weight > edges[j + 1].weight){
                //swapping lore.
                Edge temp = edges[j];
                edges[j] = edges[j + 1];
                edges[j + 1] = temp;
            }
        }
    }
}
//sorting the graph edges and picking the minimum weight edge that do not create a cycle.
Graph* Algorithms::kruskal(Graph &g){
    int vertices = g.getNumOfVertices();
    //initializing the graph only with the vertices.
    Graph* kruskalTree = new Graph(vertices);
    //allocating memory for the lagest possible edges (n choose 2).
    Edge* edges = new Edge[vertices * (vertices - 1) / 2];
    int edgeCount = 0;
    //getting all the edges from the graph.
    getAllEdges(g , edges , edgeCount);
    //sorting the edges by their weight.
    sortEdges(edges , edgeCount);
    //creating the union find data structure .
    UnionFind uf(vertices);
    for(int i = 0 ; i < edgeCount ; i++){
        int u = edges[i].source;
        int v = edges[i].dest;
        int weight = edges[i].weight;
        int superParentU = uf.find(u);
        int superParentV = uf.find(v);
        //checking if the edge creates a cycle.
        if(superParentU != superParentV){
            //adding the edge to the mst.
            kruskalTree->addEdge(u , v , weight);
            //union the two vertices.
            uf.union(u , v);
        }
    }
    //freeing the memory we needed to create the kruskal tree.
    delete[] edges;
    return kruskalTree;
}
}   