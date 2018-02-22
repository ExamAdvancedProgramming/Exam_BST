#include <iostream>
#include <memory>
#include <utility>
#include <vector>
#include <numeric>

// Files needed

#include "Class_BST.h"
#include "Iterators_BST.h"
#include "Functions_BST.h"




int main() {

    
    
    BST<int, int, Minor<int>> TreeBB{};
    TreeBB.insert(2,2);
    TreeBB.insert(2,2);
    TreeBB.insert(3,2);
    TreeBB.insert(7,7); 
    TreeBB.insert(4,3);
    TreeBB.insert(14,13);
    TreeBB.insert(6,5);
    TreeBB.insert(7,7); // node already exists!
    TreeBB.insert(9,8);
    TreeBB.insert(13,12);
    TreeBB.insert(15,14);
    TreeBB.insert(10,9);
    TreeBB.insert(20,19);
    TreeBB.insert(30,29);
    TreeBB.insert(16,15);
    
    TreeBB.print();
    
    BST<int, int, Greater<int>> Tree{};
    //Tree.print();           //expected empty
    Tree.insert(8,7);
    Tree.insert(5,4);
    Tree.insert(3,2);
    Tree.insert(7,7);
    Tree.insert(7,7); 
    Tree.insert(4,3);
    Tree.insert(14,13);
    Tree.insert(6,5);
    Tree.insert(7,7); // node already exists!
    Tree.insert(9,8);
    Tree.insert(13,12);
    Tree.insert(15,14);
    Tree.insert(10,9);
    Tree.insert(20,19);
    Tree.insert(30,29);
    Tree.insert(16,15);

    Tree.print();
    
    auto find1 = TreeBB.better_find(16);
    auto find2 = Tree.better_find(30);


    std::cout << "Found the keys " << (*find1).first << " and " << (*find2).first << std::endl; 
/*
    auto find1 = Tree.better_find(16);
    auto find2 = Tree.better_find(30);
    
    (*find2).second = 299;
    std::cout << (*find2).second << std::endl;
    auto prova = Tree.cbegin();
    //(*prova).second = 299;
    std::cout << "Found the keys " << (*find1).first << " and " << (*find2).first << std::endl; 
     std::cout << "Found PROVA " << (*prova).first << " and " << (*prova).second << std::endl; 
    
    //Tree.better_find(55);
  
    Tree.last(); // expected last key:30  and last value:29
	
	
	int v = Tree[30];
	int v1 = Tree[75];
	
	//expected new right node 75 and The references are 29 and 0
	
	std::cout << "The references are " << v << " and " << v1 << std::endl; 
    

    Tree.print();
    Tree.better_balance();
    std::cout << "               " << std::endl;
    std::cout << "Expected Tree (but balanced)" << std::endl;
    std::cout << "               " << std::endl;
    Tree.print();
    
    
    std::cout << "               " << std::endl;
    std::cout << "COPY - MOVE TEST " << std::endl;
    std::cout << "               " << std::endl;
    
    BST<int, int, Greater<int>> Other_Tree(Tree);
    BST<int, int, Greater<int>> Moved_Tree(std::move(Tree));
    BST<int, int, Greater<int>> Tree_to_be_assigned{};
    
    
    std::cout << "               " << std::endl;
    std::cout << "Expected Tree copied" << std::endl;
    std::cout << "               " << std::endl;
    
    
    Other_Tree.print();
    Other_Tree.insert(55,7);
    
    std::cout << "               " << std::endl;
    std::cout << "Expected Tree copied with 55" << std::endl;
    std::cout << "               " << std::endl;
    
    Other_Tree.print();
    
    std::cout << "               " << std::endl;
    std::cout << "Expected Empty" << std::endl;
    std::cout << "               " << std::endl;
    
    Tree.print();
    
 
 	std::cout << "               " << std::endl;
    std::cout << "NEW TREE IS BUILT" << std::endl;
    std::cout << "               " << std::endl;
 
 
    
    Tree_to_be_assigned.insert(5,7);
    Tree_to_be_assigned.insert(13,2);
    BST<int, int, Greater<int>> Tree_short{};
    Tree_short.insert(10,2);
    Tree_short.insert(20,2);
   
    std::cout << "               " << std::endl;
    std::cout << "Expected Tree copied with 55" << std::endl;
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
    std::cout << "               " << std::endl;
    
    
    Tree_to_be_assigned.print();
    Tree_to_be_assigned = Tree_short;
    Other_Tree = std::move(Tree_short);
    
    std::cout << "               " << std::endl;
    std::cout << "               " << std::endl;
    
    Tree_to_be_assigned.print();
    Other_Tree.print();
    
    std::cout << "               " << std::endl;
    std::cout << "               " << std::endl;
    
    Tree_short.print();
    
    
    std::cout << "               " << std::endl;
    std::cout << "               " << std::endl;
    
    
    Other_Tree.clear();
    
    std::cout << "Expected empty" << std::endl;
    Other_Tree.print();
    
    */
    };


