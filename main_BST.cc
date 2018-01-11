#include <iostream>
#include <memory>

// Files needed

#include "Class_BST.cc"
#include "Iterators_BST.cc"
#include "Functions_BST.cc"



int main() {
    
    BST<int, int> Tree{};
    Tree.insert(8,2);
    Tree.insert(5,2);
    Tree.insert(3,3);
    Tree.insert(7,3);
    Tree.insert(4,2);
    Tree.insert(14,1);
    Tree.insert(6,2);
    Tree.insert(9,2);
    Tree.insert(13,2);
    Tree.insert(15,2);
    Tree.insert(10,2);
    Tree.insert(20,2);
    Tree.insert(30,2);
    Tree.insert(16,2);
    Tree.print();
    std::cout << "funziona lo scheletro" << std::endl;
    
    };


