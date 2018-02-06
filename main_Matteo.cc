#include <iostream>
#include <memory>
#include <utility>
#include <vector>
#include <numeric>
#include <ctime>
#include <math.h>

// Files needed

#include "Class_BST.cc"
#include "Iterators_BST.cc"
#include "Functions_BST.cc"




int main() {
    
    /// CONSTRUCTION OF THE TWO DIFFERENT TREES ///
    
    BST<int, int> Treeb{};
    //Tree.print();           //expected empty
    std::vector<int> keysb{};
    std::vector<int> keysB{};
    int nb = 100;
    int nB = 1000;
    
    for (int i=0; i<nb; i++){
        int r1 = rand();
        Treeb.insert(r1,rand());
        if (i%5 == 0){
            keysb.push_back(r1);
        }
    }

    BST<int, int> TreeB{};
    
    for (int i=0; i<nB; i++){
        int r1 = rand();
        TreeB.insert(r1,rand());
        if (i%50 == 0){
            keysB.push_back(r1);
        }
    }

    /// CHECKING THE TIME TO FIND THE WANTED NODES ON THE NON-BALANCED TREES ///
    
    std::clock_t startb;
    double durationb;
    startb = std::clock();

        for (int i=0; i<20; i++){
            Treeb.better_find(keysb[i]);
        } 

    durationb = ( std::clock() - startb ) / (double) CLOCKS_PER_SEC;
    
    std::clock_t startB;
    double durationB;
    startB = std::clock();

        for (int i=0; i<20; i++){
            TreeB.better_find(keysB[i]);
        }

    durationB = ( std::clock() - startB ) / (double) CLOCKS_PER_SEC;
    
    /// BALANCING THE TREES ///
    
    Treeb.balance();
    
    TreeB.balance();
    
    /// CHECKING THE TIME TO FIND THE WANTED NODES ON THE BALANCED TREES ///
    
    std::clock_t Bal_startb;
    double Bal_durationb;
    Bal_startb = std::clock();

        for (int i=0; i<20; i++){
            Treeb.better_find(keysb[i]);
        }

    Bal_durationb = ( std::clock() - Bal_startb ) / (double) CLOCKS_PER_SEC;
    
    std::clock_t Bal_startB;
    double Bal_durationB;
    Bal_startB = std::clock();

        for (int i=0; i<20; i++){
            TreeB.better_find(keysB[i]);
        }

    Bal_durationB = ( std::clock() - Bal_startB ) / (double) CLOCKS_PER_SEC;
    
    /// PRINTING THE RESULTS
    
    std::cout<<"Spent time for finding in b: "<< durationb <<std::endl;
    std::cout<<"Spent time for finding in B: "<< durationB <<std::endl;
    std::cout<<"Spent time for finding in balanced b: "<< Bal_durationb <<std::endl;
    std::cout<<"Spent time for finding in balanced B: "<< Bal_durationB <<std::endl;
    
    std::cout<<"Comparison between times: log(n)/log(N) = " << log10(nb)/log10(nB) << ";  " << "Tb/TB = "<< Bal_durationb/Bal_durationB << "." << std::endl;
    
    /*
    std::cout << "Giving the last pair: "<< std::endl;
    Tree.last();
    Tree.print();
    Tree.better_balance();
    std::cout << "               " << std::endl;
    std::cout << "Expected Tree (but balanced)" << std::endl;
    std::cout << "               " << std::endl;
    
    Tree.print();
    
    std::cout << "               " << std::endl;
    std::cout << "COPY - MOVE TEST " << std::endl;
    std::cout << "               " << std::endl;
    
    BST<int, int> Other_Tree(Tree);
    BST<int, int> Moved_Tree(std::move(Tree));
    BST<int, int> Tree_to_be_assigned{};
    
    
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
    std::cout << "New Tree" << std::endl;
    std::cout << "               " << std::endl;
    
    
    Tree_to_be_assigned.insert(5,7);
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
    */
    
    std::cout << "FUNZIONA" << std::endl;
    
    };


