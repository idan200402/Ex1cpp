//idan.shumski@gmail.com

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "algorithms.h"
#include "stdexcept"
#include <climits>
#include "test_helpers.h"
//test file for the dijkstra algorithm.
using namespace graph;



TEST_CASE("Dijkstra algorithm"){
    SUBCASE("testing a simple connected graph"){
        Graph g(4);
        g.addEdge(0, 1, 1);
        g.addEdge(0, 2, 4);
        g.addEdge(1, 3, 2);
        g.addEdge(1, 2, 1);

        Graph* dijkstraTree = Algorithms::dijkstra(g , 0);
        CHECK(dijkstraTree->getNumOfVertices() == 4);
        CHECK(findEdgeWeight(*dijkstraTree, 0, 1) == 1);
        CHECK(findEdgeWeight(*dijkstraTree, 1, 3) == 2);
        CHECK(findEdgeWeight(*dijkstraTree, 1, 2) == 1);
        CHECK(findEdgeWeight(*dijkstraTree, 0, 2) == -1); // this edge should not be in the dijkstra tree.
        delete dijkstraTree;

    }
    SUBCASE("testing a grpah with negative weight"){
        Graph g(4);
        g.addEdge(0, 1, 1);
        g.addEdge(0, 2, -4);
        g.addEdge(1, 3, 2);
        g.addEdge(1, 2, 1);
        CHECK_THROWS_AS(Algorithms::dijkstra(g , 0), std::invalid_argument);
    }
    SUBCASE("testing a disconnected graph"){
        Graph g(4);
        g.addEdge(0, 1, 1);
        g.addEdge(2, 3, 1);
        Graph* dijkstraTree = Algorithms::dijkstra(g , 0);
        CHECK(dijkstraTree->getNumOfVertices() == 4);
        CHECK(findEdgeWeight(*dijkstraTree, 0, 1) == 1);
        CHECK(findEdgeWeight(*dijkstraTree, 2, 3) == -1);
        delete dijkstraTree;
    }
}   