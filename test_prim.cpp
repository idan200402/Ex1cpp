//idan.shumski@gmail.com

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "algorithms.h"
#include "stdexcept"
#include "test_helpers.h"
//test file for the prim algorithm.
using namespace graph;


TEST_CASE("Prim algorithm"){
    SUBCASE("testing a simple connected graph"){
        Graph g(4);
        g.addEdge(0, 1, 1);
        g.addEdge(0, 2, 3);
        g.addEdge(0, 3, 2);
        g.addEdge(2, 3, 4);
        g.addEdge(1, 2, 1);

        Graph* primTree = Algorithms::prim(g);
        CHECK(primTree->getNumOfVertices() == 4);
        CHECK(calculateTotalWeight(*primTree) == 4); // the total weight of the minimum spanning tree should be 4.
        delete primTree;
    }
    SUBCASE("testing a disconnected graph"){
        Graph g(4);
        g.addEdge(0, 1, 1);
        g.addEdge(2, 3, 1);
        CHECK_THROWS_AS(Algorithms::prim(g), std::invalid_argument);
    }
    SUBCASE("testing prim all an empty graph"){
        Graph g(0);
        CHECK_THROWS_AS(Algorithms::prim(g), std::invalid_argument);
    }

}