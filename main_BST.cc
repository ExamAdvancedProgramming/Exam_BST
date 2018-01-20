#include <iostream>
#include <memory>

// Files needed

#include "Class_BST.cc"
#include "Iterators_BST.cc"
#include "Functions_BST.cc"



int main() {
    
    BST<int, int> Tree{};
    Tree.print();           //expected empty
    Tree.insert(8,7);
    Tree.insert(5,4);
    Tree.insert(3,2);
    Tree.insert(7,6);
    Tree.insert(4,3);
    Tree.insert(14,13);
    Tree.insert(6,5);
    Tree.insert(7,6); // node already exists!
    Tree.insert(9,8);
    Tree.insert(13,12);
    Tree.insert(15,14);
    Tree.insert(10,9);
    Tree.insert(20,19);
    Tree.insert(30,29);
    Tree.insert(16,15);
    auto find1 = Tree.find(16);
    auto find2 = Tree.find(30); 
    Tree.find(55);
    std::cout << "Found the keys " << (*find1).first << " and " << (*find2).second << std::endl;
    Tree.print();
    //Tree.clear();
    //Tree.print();           //expected empty
    
    
    std::cout << "               " << std::endl;
    std::cout << "COPY - MOVE TEST " << std::endl;
    std::cout << "               " << std::endl;
    
    BST<int, int> Other_Tree(Tree);
    BST<int, int> Moved_Tree(std::move(Tree));
    BST<int, int> Tree_to_be_assigned{};
    Tree_to_be_assigned.insert(5,7),
    Tree_to_be_assigned.insert(13,2);
    BST<int, int> Tree_short{};
    Tree_short.insert(10,2);
    Tree_short.insert(20,2);
   
    std::cout << "               " << std::endl;
    std::cout << "Expected Tree" << std::endl;
    std::cout << "               " << std::endl;
    
    Other_Tree.print();
    
    std::cout << "               " << std::endl;
    std::cout << "Expected empty" << std::endl;
    std::cout << "               " << std::endl;
    
    Tree.print();
    
    std::cout << "               " << std::endl;
    std::cout << "Expected Tree" << std::endl;
    std::cout << "               " << std::endl;
    
    Moved_Tree.print();
    
    std::cout << "               " << std::endl;
    std::cout << "Expected [5 : 7] [13 : 2]" << std::endl;
    std::cout << "               " << std::endl;
    
    Tree_to_be_assigned.print();
    Tree_to_be_assigned = Tree_short;
    Other_Tree = std::move(Tree_short);
    
    std::cout << "               " << std::endl;
    std::cout << "Expected [10 : 2] [20 : 2] for both trees" << std::endl;
    std::cout << "               " << std::endl;
    
    Tree_to_be_assigned.print();
    Other_Tree.print();
    
    std::cout << "               " << std::endl;
    std::cout << "Expected empty" << std::endl;
    std::cout << "               " << std::endl;
    
    Tree_short.print();
    
    
    std::cout << "               " << std::endl;
    std::cout << "CLEAR TEST " << std::endl;
    std::cout << "               " << std::endl;
    
    
    Other_Tree.clear();
    std::cout << "Expected empty" << std::endl;
    Other_Tree.print();
    
    std::cout << "FUNZIONA" << std::endl;
    
    };


