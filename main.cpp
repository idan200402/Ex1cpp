#include "algorithms.h"
#include <iostream>
#include <stdexcept>

using namespace graph;
// Function to create a simple graph for testing
// This function creates a graph with 5 vertices and adds some edges
Graph createSimpleGraph() {
    std::cout << "Creating a graph that made just for you!" << std::endl;
    int vertices;
    std::cout << "Enter the number of vertices: ";
    std::cin >> vertices;
    Graph g(vertices);
    int edges;
    std::cout << "Enter the number of edges: ";
    std::cin >> edges;
    if(edges < 0 || edges > vertices * (vertices - 1) / 2) {
        throw std::invalid_argument("Invalid number of edges.");

    }
    for (int i = 0; i < edges; ++i) {
        int src, dest, weight;
        std::cout << "Enter edge (src dest weight): ";
        std::cin >> src >> dest >> weight;
        if(src < 0 || src >= vertices || dest < 0 || dest >= vertices) {
            std::cerr << "Invalid edge. Please enter valid vertices." << std::endl;
            --i; 
        }
        else{g.addEdge(src, dest, weight);}
    }
    return g;

}
int main() {
    try{
        std::cout << "Creating a graph." << std::endl;
        Graph g = createSimpleGraph();
        std::cout << "Graph representation as adjacency list:" << std::endl;
        g.displayGraph();
        //Algorithms alg;
        // initializing a default source vertex , user choice and result graph.
        int source = 0;
        int choice = 0; 
        Graph* result = nullptr;
        Graph case_6_g(0); // this is the new graph that will be created in case 6.
        //in case the user would like to create his own graph(will be rearrenged in case 6).
        while(true){
            std::cout << "Choose an algorithm to run on the graph:" << std::endl;
            std::cout << "1. BFS" << std::endl;
            std::cout << "2. DFS" << std::endl;
            std::cout << "3. Dijkstra" << std::endl;
            std::cout << "4. Prim" << std::endl;
            std::cout << "5. Kruskal" << std::endl;
            std::cout << "0. Exit" << std::endl;
            std::cout << "Enter your choice: ";
            std::cin >> choice;
            if(choice == 0){
                std::cout << "Exiting the program." << std::endl;
                break;
            }
            switch(choice){
                case 1:
                    std::cout << "Enter source vertex between 0 - "
                    <<g.getNumOfVertices()-1 << std::endl;
                    std::cin >> source;
                    try{
                        result = Algorithms::bfs(g , source);
                        std::cout << "BFS tree:" << std::endl;
                        result->displayGraph();
                        delete result;
                        result = nullptr;
                    } catch(const std::out_of_range &e){
                        std::cerr<<"Error: " << e.what() << std::endl;
                    } catch(const std::invalid_argument &e){
                        std::cerr<<"Error: " << e.what() << std::endl;
                    }
                    break;
                case 2:
                    std::cout << "Enter source vertex between 0 - "
                    <<g.getNumOfVertices()-1 << std::endl;
                    std::cin >> source;
                    try{
                        result = Algorithms::dfs(g , source);
                        std::cout << "DFS tree:" << std::endl;
                        result->displayGraph();
                        delete result;
                    } catch(const std::out_of_range &e){
                        std::cerr<<"Error: " << e.what() << std::endl;
                    } catch(const std::invalid_argument &e){
                        std::cerr<<"Error: " << e.what() << std::endl;
                    }
                    break;
                        
                case 3:
                    std::cout << "Enter source vertex between 0 - "
                    <<g.getNumOfVertices()-1 << std::endl;
                    std::cin >> source;
                    try{
                        result = Algorithms::dijkstra(g , source);
                        std::cout << "Dijkstra tree:" << std::endl;
                        result->displayGraph();
                        delete result;
                    } catch(const std::out_of_range &e){
                        std::cerr<<"Error: " << e.what() << std::endl;
                    } catch(const std::invalid_argument &e){
                        std::cerr<<"Error: " << e.what() << std::endl;
                    }
                    break;
                case 4:
                    try{
                        result = Algorithms::prim(g);
                        std::cout << "Prim tree:" << std::endl;
                        result->displayGraph();
                        delete result;
                    } catch(const std::runtime_error &e){
                        std::cerr<<"Error: " << e.what() << std::endl;
                    }
                    break;
                case 5:
                    try{
                        result = Algorithms::kruskal(g);
                        std::cout << "Kruskal tree:" << std::endl;
                        result->displayGraph();
                        delete result;
                    } catch(const std::runtime_error &e){
                        std::cerr<<"Error: " << e.what() << std::endl;
                    }
                    break;
                
                default:
                    std::cout << "Invalid choice. Please try again." << std::endl;
                    break;
            }
        }
    
    } catch (const std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1; // error indicator
    }
    std::cout << "Program ends successfully." << std::endl;
    return 0; // success indicator
}