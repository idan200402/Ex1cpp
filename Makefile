CC = g++
CFLAGS = -Wall -std=c++11
TARGET = graph_algorithms
SOURCES = main.cpp algorithms.cpp dataStructures.cpp graph.cpp linkedList.cpp 
OBJECTS = $(SOURCES:.cpp=.o)
HEADERS = algorithms.h dataStructures.h graph.h linkedList.h
all : $(TARGET)

#linking 
$(TARGET) : $(OBJECTS)
	$(CC) $(CFLAGS) -o $@ $^

#compiling

%.o : %.cpp $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

#cleaning
clean :
	rm -f $(OBJECTS) $(TARGET)

#running
run : $(TARGET)
	./$(TARGET)
	

.PHONY : all clean