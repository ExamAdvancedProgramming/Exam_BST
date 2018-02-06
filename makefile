HEADERS = Class_BST.h Iterators.h Functions.h
OBJECTS = main_BST.o

default: main_BST

%.o: %.c $(HEADERS)
	g++ -std=c++11 $< -o $@

program: $(OBJECTS)
	g++ -std=c++11 $(OBJECTS) -o $@

clean:
	-rm -f $(OBJECTS)
	-rm -f main_BST
