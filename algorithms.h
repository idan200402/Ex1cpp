#ifndef ALGORITHMS_H
#define ALGORITHMS_H
#include "graph.h"
#include "dataStructures.h"

namespace graph{
class Algorithms{
//declaring the different algorithm as static methods , because there is no need to create an instance of the class to use the algorithms.
//also declared some private helper methods to be used in the implementation of the algorithms.
public:
static Graph *bfs(Graph &graph , int startVertex);
static Graph *dfs(Graph &graph , int startVertex);
static Graph *dijkstra(Graph &graph , int startVertex);
static Graph *prim(Graph &graph );
static Graph *kruskal(Graph &graph);
private:
static void dfsHelper(Graph &graph , int vertex , bool *visited , Graph *res);
static void getAllEdges(Graph &graph , Edge* edges , int &edgeCount);
static void sortEdges(Edge* edges , int edgeount);

};

}

#endif