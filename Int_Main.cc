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
    
    int nb = 5000;
    int nB = 50000;
    
    for (int i=0; i<nb; i++){
        int r1 = rand();
        Treeb.insert(rand(),rand());
     }
    

    BST<int, int> TreeB{};
    
    for (int i=0; i<nB; i++){
        TreeB.insert(rand(),rand());
    }

    /// CHECKING THE TIME TO FIND THE WANTED NODES ON THE NON-BALANCED TREES ///
    
    std::clock_t startb;
    double durationb;
    startb = std::clock();

        for (int i=0; i<nb; i++){
            Treeb.find(rand());
        } 

    durationb = ( std::clock() - startb ) / (double) CLOCKS_PER_SEC;
    
    std::clock_t startB;
    double durationB;
    startB = std::clock();

        for (int i=0; i<nB; i++){
            TreeB.find(rand());
        }

    durationB = ( std::clock() - startB ) / (double) CLOCKS_PER_SEC;
    
    /// BALANCING THE TREES ///
    
    Treeb.better_balance();
    
    TreeB.better_balance();
    
    /// CHECKING THE TIME TO FIND THE WANTED NODES ON THE BALANCED TREES ///
    
    std::clock_t Bal_startb;
    double Bal_durationb;
    Bal_startb = std::clock();

        for (int i=0; i<nb; i++){
            Treeb.find(rand());
        } 

    Bal_durationb = ( std::clock() - Bal_startb ) / (double) CLOCKS_PER_SEC;
    
    std::clock_t Bal_startB;
    double Bal_durationB;
    Bal_startB = std::clock();

        for (int i=0; i<nB; i++){
            TreeB.find(rand());
        }

    Bal_durationB = ( std::clock() - Bal_startB ) / (double) CLOCKS_PER_SEC;
    
    /// PRINTING THE RESULTS
    
    std::cout<<"Spent time for finding in b: "<< durationb <<std::endl;
    std::cout<<"Spent time for finding in B: "<< durationB <<std::endl;
    std::cout<<"Spent time for finding in balanced b: "<< Bal_durationb <<std::endl;
    std::cout<<"Spent time for finding in balanced B: "<< Bal_durationB <<std::endl;
    
    std::cout<<"Comparison between times: log(n)/log(N) = " << log10(nb)/log10(nB) << ";  " << "Tb/TB = "<< Bal_durationb/Bal_durationB << "." << std::endl;
    
    
    }
