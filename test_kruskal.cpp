#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "algorithms.h"
#include <stdexcept>
#include "test_helpers.h"

using namespace graph;

TEST_CASE("Kruskal algorithm") {
    SUBCASE("testing a simple connected graph") {
        Graph g(4);
        g.addEdge(0, 1, 1);
        g.addEdge(0, 2, 3);
        g.addEdge(0, 3, 2);
        g.addEdge(2, 3, 4);
        g.addEdge(1, 2, 1);

        Graph* kruskalTree = Algorithms::kruskal(g);
        kruskalTree->displayGraph();
        CHECK(kruskalTree->getNumOfVertices() == 4);
        CHECK(calculateTotalWeight(*kruskalTree) == 4); 
        Graph* primTree = Algorithms::prim(g);
        CHECK(calculateTotalWeight(*primTree) == calculateTotalWeight(*kruskalTree)); 
        delete kruskalTree;
        delete primTree;
    }
    SUBCASE("testing a disconnected graph") {
        Graph g(4);
        g.addEdge(0, 1, 1);
        g.addEdge(2, 3, 1);
        CHECK_THROWS_AS(Algorithms::kruskal(g), std::runtime_error);
    }
    SUBCASE("testing kruskal on an empty graph") {
        Graph g(0);
        CHECK_THROWS_AS(Algorithms::kruskal(g), std::invalid_argument);
    }
}

