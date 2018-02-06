CC=g++
CFLAGS=-std=c++11 -Wall -Wextra
SOURCES=main_BST.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=Try

all: $(SOURCES) $(EXECUTABLE)
    
$(EXECUTABLE): $(OBJECTS) 
	$(CC) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@
