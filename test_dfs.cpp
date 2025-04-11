#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "algorithms.h"
#include "stdexcept"
#include "test_helpers.h"

using namespace graph;



TEST_CASE("DFS ALGORITHM"){
    SUBCASE("DFS where the graph is connected and simple"){
        Graph g(4);
        g.addEdge(0, 1, 1);
        g.addEdge(1  , 2 , 1);   
        g.addEdge(2 , 3 , 1);
        Graph* dfsTree = Algorithms::dfs(g , 0);
        CHECK(dfsTree->getNumOfVertices() == 4);
        CHECK(edgeExists(*dfsTree, 0, 1));
        bool exp1 = edgeExists(*dfsTree, 1, 2);
        bool exp2 = edgeExists(*dfsTree, 2, 3);
        bool res = exp1 || exp2;
        CHECK(res);
        delete dfsTree;

    }
    SUBCASE("DFS where the graph is disconnected"){
        Graph g(4);
        g.addEdge(0, 1, 1);
        g.addEdge(2, 3, 1);
        Graph* dfsTree = Algorithms::dfs(g , 0);
        dfsTree->displayGraph();
        CHECK(dfsTree->getNumOfVertices() == 4);
        CHECK(edgeExists(*dfsTree, 0, 1));
        bool exp1= edgeExists(*dfsTree , 2 , 3);
        bool exp2 = edgeExists(*dfsTree , 1 , 2);
        bool res = exp1 || exp2;
        CHECK(res);
        CHECK_FALSE(edgeExists(*dfsTree , 1 , 2));
        CHECK_FALSE(edgeExists(*dfsTree , 1 , 3));
        delete dfsTree;
    }
}