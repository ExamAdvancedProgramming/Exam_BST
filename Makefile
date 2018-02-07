OBJECTS = main_BST.o 
CXXFLAGS = -g -std=c++11 -Wall -Wextra 
CXX = g++
PROGRAM_NAME = true_main
PROGRAM_NAME_STR = string_main
PROGRAM_NAME_INT = integer_main

$(PROGRAM_NAME) : main_BST.o 
	$(CXX) $(CXXFLAGS) -o $(PROGRAM_NAME) $(OBJECTS) 
	
string : String_Lookup_Comparison.o
	$(CXX) $(CXXFLAGS) -o $(PROGRAM_NAME_STR) String_Lookup_Comparison.o
	
integer : Integer_Lookup_Comparison.o 
	$(CXX) $(CXXFLAGS) -o $(PROGRAM_NAME_INT) Integer_Lookup_Comparison.o
