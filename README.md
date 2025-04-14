EX1 Systems Programming 2
========================
This assignment is about implementing various graph algorithms using cpp. moreover, we also implemented a adjacency list for representing a graph and all the data structures needed for the algorithms such as queue , a priority queue and a union find data structure. We also implemented a simple command line interface for the user to interact , unit tests for the algorithms functionality , makefile for building the project and a valgrind file for checking memory leaks accross the project.

The project is divided into several utilities:
- **Graph**: This module implements a graph using an adjacency list representation. Each node in the adjacency list is represented by a `Node` struct, which contains the node's value (edge weight) and a pointer to the next node in the list , which is used to represent the edges of the graph.
- **Algorithms**: This module implements various graph algorithms, Breadth First Search (BFS), Depth First Search (DFS), Dijkstra's algorithm, Prim's algorithm, and Kruskal's algorithm. Each algorithm represents as a static method of the `Algorithms` class. The algorithms are implemented using the graph representation provided by the `Graph` module.
- **Data Structures**: This module implements various data structures used in the algorithms, queue , that been used in BFS and DFS, a priority queue that been used in Dijkstra's and Prim's algorithms, and a union find data structure that been used in Kruskal's algorithm. Each data structure is implemented as a class with attributes and methods.
- **Tests**: This module contains unit tests for the algorithms methods. The test are implemented using doctest framework. The tests are designed to check the functionality of the algorithms and ensure that they work correctly with various input graphs eg connected, disconnected, empty, cyclic, etc.
- **Memory Leak Check**: This module contains a valgrind file that can be used to check for memory leaks in the project. this check ensures that all the dinamically allocated memory is properly freed and that there are no memory leaks in the process.

How To Run The Project:
1.To run the main program type in the terminal: make run
2. To run all the tests type in the terminal: make test
3. To run the valgrind check for alll the tests type in the terminal: make valgrind
4. To run the valgrind check for the main program type in the terminal: make valgrind_main
5. To clean the build files type in the terminal: make clean
6. to build the main program and the tests, run the following command in the terminal: make
to run the main program, run the following command in the terminal: ./main
to run a test , for example the test for BFS algorithm, run the following command in the terminal: ./test_bfs\

Requirements:
- compiler: g++  , C++11.
- valgrind: For memory leak check.
- Doctest: For unit testing.

Author:
- **Name**: Idan Shumski
- **Email**: idan.shumski@gmail.com


