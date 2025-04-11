#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "algorithms.h"
#include "stdexcept"
#include "test_helpers.h"   

using namespace graph;


// Test case for BFS algorithm
TEST_CASE("BFS algorithm") {
    SUBCASE("testing a simple connected graph") {
        Graph g(4);
        g.addEdge(0, 1, 1);
        g.addEdge(0, 2, 1);
        g.addEdge(0, 3, 1);
        g.addEdge(1, 2, 1);

        Graph* bfsTree = Algorithms::bfs(g, 0);
        CHECK(bfsTree->getNumOfVertices() == 4);
        CHECK(edgeExists(*bfsTree, 0, 1));
        CHECK(edgeExists(*bfsTree, 0, 2));
        CHECK(edgeExists(*bfsTree, 0, 3));

        CHECK_FALSE(edgeExists(*bfsTree, 1, 2));

        delete bfsTree;
    }

    SUBCASE("testing a disconnected graph") {
        Graph g(4);
        g.addEdge(0, 1, 1);
        g.addEdge(2, 3, 1);
        Graph* bfsTree = Algorithms::bfs(g, 0);
        CHECK(bfsTree->getNumOfVertices() == 4);
        CHECK(edgeExists(*bfsTree, 0, 1));
        CHECK_FALSE(edgeExists(*bfsTree, 2, 3));
        CHECK_FALSE(edgeExists(*bfsTree, 1, 2));

        delete bfsTree;
    }
    SUBCASE("testing a graph with in valid source") {
        Graph g(4);
        g.addEdge(0, 1, 1);
        g.addEdge(1, 2, 1);
        g.addEdge(2, 3, 1);
        CHECK_THROWS_AS(Algorithms::bfs(g, -1), std::out_of_range);
        CHECK_THROWS_AS(Algorithms::bfs(g, 4), std::out_of_range);
    }
}