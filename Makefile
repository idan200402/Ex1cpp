CC = g++
CFLAGS = -Wall -std=c++11
TARGET = graph_algorithms  
SOURCES = main.cpp algorithms.cpp dataStructures.cpp graph.cpp linkedList.cpp 
OBJECTS = $(SOURCES:.cpp=.o)
HEADERS = algorithms.h dataStructures.h graph.h linkedList.h 
all : $(TARGET)
TEST_BFS = test_bfs
TEST_DFS = test_dfs
TEST_DIJKSTRA = test_dijkstra
TEST_PRIM = test_prim
TEST_KRUSKAL = test_kruskal
ALL_TESTS = $(TEST_BFS) $(TEST_DFS) $(TEST_DIJKSTRA) $(TEST_PRIM) $(TEST_KRUSKAL)
TEST_BFS_SRC = test_bfs.cpp algorithms.cpp dataStructures.cpp graph.cpp linkedList.cpp
TEST_DFS_SRC = test_dfs.cpp algorithms.cpp dataStructures.cpp graph.cpp linkedList.cpp
TEST_DIJKSTRA_SRC = test_dijkstra.cpp algorithms.cpp dataStructures.cpp graph.cpp linkedList.cpp
TEST_PRIM_SRC = test_prim.cpp algorithms.cpp dataStructures.cpp graph.cpp linkedList.cpp
TEST_KRUSKAL_SRC = test_kruskal.cpp algorithms.cpp dataStructures.cpp graph.cpp linkedList.cpp
#linking 
$(TARGET) : $(OBJECTS) 
	$(CC) $(CFLAGS) -o $@ $^

#compiling

%.o : %.cpp $(HEADERS) 
	$(CC) $(CFLAGS) -c $< -o $@

$(TEST_BFS): $(TEST_BFS_SRC)  $(HEADERS) test_helpers.h
	$(CC) $(CFLAGS) -o $@ $(TEST_BFS_SRC)

$(TEST_DFS): $(TEST_DFS_SRC) $(HEADERS) test_helpers.h
	$(CC) $(CFLAGS) -o $@ $(TEST_DFS_SRC)

$(TEST_DIJKSTRA): $(TEST_DIJKSTRA_SRC) $(HEADERS) test_helpers.h
	$(CC) $(CFLAGS) -o $@ $(TEST_DIJKSTRA_SRC)

$(TEST_PRIM): $(TEST_PRIM_SRC) $(HEADERS) test_helpers.h
	$(CC) $(CFLAGS) -o $@ $(TEST_PRIM_SRC)

$(TEST_KRUSKAL): $(TEST_KRUSKAL_SRC) $(HEADERS)
	$(CC) $(CFLAGS) -o $@ $(TEST_KRUSKAL_SRC)

#add here other tests

test: $(ALL_TESTS)
	@echo "Running tests"
	@for test in $(ALL_TESTS) ; do \
		echo "Running $$test"; \
		./$$test; \
	done
	@echo "All tests completed"

valgrind: $(ALL_TESTS)
	@echo "Running tests with valgrind"
	@for test in $(ALL_TESTS) ; do \
		echo "Running $$test with valgrind"; \
		valgrind --leak-check=full --show-leak-kinds=all ./$$test; \
	done
	@echo "All tests completed with valgrind"

valgrind_main: $(TARGET)
	@echo "Running main with valgrind"
	valgrind --leak-check=full --show-leak-kinds=all ./$(TARGET)
	@echo "Main completed with valgrind"





#cleaning
clean :
	rm -f $(OBJECTS) $(TARGET) $(ALL_TESTS) 

#running
run : $(TARGET)
	./$(TARGET)
	

.PHONY : all clean test run valgrind valgrind_main