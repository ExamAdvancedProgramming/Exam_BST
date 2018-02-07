OBJECTS = main_BST.o 
CXXFLAGS = -g -std=c++11 -Wall -Wextra 
CXX = g++
PROGRAM_NAME = prova

$(PROGRAM_NAME) : main_BST.o 
	$(CXX) $(CXXFLAGS) -o $(PROGRAM_NAME) $(OBJECTS) 
	
main_BST.o:main_BST.cc Class_BST.h Functions_BST.h Iterators_BST.h 
