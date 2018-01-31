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
    
    int nb = 100000;
    int nB = 500000;
    int nBB = 1000000;
    
    for (int i=0; i<nb; i++){
        Treeb.insert(rand(),1);
     }
    

    BST<int, int> TreeB{};
    
    for (int i=0; i<nB; i++){
        TreeB.insert(rand(),1);
    }
    
    
    BST<int, int> TreeBB{};
    
    for (int i=0; i<nBB; i++){
        TreeBB.insert(rand(),1);
    }
    
    
    /// CHECKING THE TIME TO FIND THE WANTED NODES ON THE NON-BALANCED TREES ///
    
    std::clock_t startb;
    double durationb;
    startb = std::clock();

        for (int i=0; i<nb; i++){
            Treeb.better_find(rand());
        } 

    durationb = ( std::clock() - startb ) / (double) CLOCKS_PER_SEC;
    
    std::clock_t startB;
    double durationB;
    startB = std::clock();

        for (int i=0; i<nB; i++){
            TreeB.better_find(rand());
        }

    durationB = ( std::clock() - startB ) / (double) CLOCKS_PER_SEC;
    
    
    std::clock_t startBB;
    double durationBB;
    startB = std::clock();

        for (int i=0; i<nBB; i++){
            TreeBB.better_find(rand());
        }

    durationBB = ( std::clock() - startBB ) / (double) CLOCKS_PER_SEC;
    
    /// BALANCING THE TREES ///
    
    Treeb.better_balance();
    
    TreeB.better_balance();
    
    TreeBB.better_balance();
    
    
    /// CHECKING THE TIME TO FIND THE WANTED NODES ON THE BALANCED TREES ///
    
    std::clock_t Bal_startb;
    double Bal_durationb;
    Bal_startb = std::clock();

        for (int i=0; i<nb; i++){
            Treeb.better_find(rand());
        } 

    Bal_durationb = ( std::clock() - Bal_startb ) / (double) CLOCKS_PER_SEC;
    
    std::clock_t Bal_startB;
    double Bal_durationB;
    Bal_startB = std::clock();

        for (int i=0; i<nB; i++){
            TreeB.better_find(rand());
        }

    Bal_durationB = ( std::clock() - Bal_startB ) / (double) CLOCKS_PER_SEC;
    
    std::clock_t Bal_startBB;
    double Bal_durationBB;
    Bal_startBB = std::clock();

        for (int i=0; i<nBB; i++){
            TreeBB.better_find(rand());
        }

    Bal_durationBB = ( std::clock() - Bal_startBB ) / (double) CLOCKS_PER_SEC;
    
    /// PRINTING THE RESULTS
    
    std::cout<<"Spent time for finding in b: "<< durationb <<std::endl;
    std::cout<<"Spent time for finding in B: "<< durationB <<std::endl;
    std::cout<<"Spent time for finding in BB: "<< durationBB <<std::endl;
    std::cout<<"Spent time for finding in balanced b: "<< Bal_durationb <<std::endl;
    std::cout<<"Spent time for finding in balanced B: "<< Bal_durationB <<std::endl;
    std::cout<<"Spent time for finding in balanced BB: "<< Bal_durationBB <<std::endl;
    
    
    std::cout<<"Comparison between times: log(n)/log(N) = " << log10(nb)/log10(nB) << ";  " << "Tb/TB = "<< Bal_durationb/Bal_durationB << "." << std::endl;
    


    }
