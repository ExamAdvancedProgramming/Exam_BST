OBJECTS = main_BST.o 
CXXFLAGS = -g -std=c++11 -Wall -Wextra 
CXX = g++
PROGRAM_NAME = check_main
PROGRAM_NAME_STR = string
PROGRAM_NAME_INT = integer

.PHONY : clean plot

all : check_main string integer 

check_main : main_BST.o Class_BST.h Functions_BST.h Iterators_BST.h
	$(CXX) $(CXXFLAGS) -o $(PROGRAM_NAME) $(OBJECTS) 
	
string : String_Lookup_Comparison.o Class_BST.h Functions_BST.h Iterators_BST.h
	rm -rf String_comparison.txt 
	$(CXX) $(CXXFLAGS) -o $(PROGRAM_NAME_STR) String_Lookup_Comparison.o 
	
integer : Integer_Lookup_Comparison.o Class_BST.h Functions_BST.h Iterators_BST.h 
	rm -rf Integer_comparison.txt 
	$(CXX) $(CXXFLAGS) -o $(PROGRAM_NAME_INT) Integer_Lookup_Comparison.o
	
clean : 
	rm -rf *.o check_main string integer
	
plot :
	rm -rf *.png
	python test_plot.py 
