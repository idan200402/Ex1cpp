CC = g++
CFLAGS = -Wall -std=c++11
all: graph_program
graph_program: main.o graph.o linkedList.o
	$(CC) $(CFLAGS) -o graph_program main.o graph.o linkedList.o

main.o: main.cpp graph.h 
	$(CC) $(CFLAGS) -c main.cpp

graph.o: graph.cpp graph.h linkedList.h
	$(CC) $(CFLAGS) -c graph.cpp

linkedList.o: linkedList.cpp linkedList.h node.h
	$(CC) $(CFLAGS) -c linkedList.cpp

clean:
	rm -f *.o graph_program
