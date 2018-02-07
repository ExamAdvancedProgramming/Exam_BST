#include <fstream>
#include <ctime>
#include <iostream>
#include <string>
#include <vector>
#include <numeric>
#include <math.h>

// Files needed

#include "Class_BST.h"
#include "Iterators_BST.h"
#include "Functions_BST.h"






int main() {
    
    /// CONSTRUCTION OF THE TWO DIFFERENT TREES ///
    
    BST<int, int> Treeb{};
    //Tree.print();           //expected empty
    
    int nb = 10000;
    int nB = 100000;
    int nBB = 1000000;
    int nBBB = 10000000;
    int nBBBB = 50000000;
 
    
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
    
    BST<int, int> TreeBBB{};
    
    for (int i=0; i<nBBB; i++){
        TreeBBB.insert(rand(),1);
    }
    
    
    BST<int, int> TreeBBBB{};
    
    for (int i=0; i<nBBBB; i++){
        TreeBBBB.insert(rand(),1);
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
    startBB = std::clock();

        for (int i=0; i<nBB; i++){
            TreeBB.better_find(rand());
        }

    durationBB = ( std::clock() - startBB ) / (double) CLOCKS_PER_SEC;
    
    std::clock_t startBBB;
    double durationBBB;
    startBBB = std::clock();

        for (int i=0; i<nBBB; i++){
            TreeBBB.better_find(rand());
        }

    durationBBB = ( std::clock() - startBBB ) / (double) CLOCKS_PER_SEC;
    
    std::clock_t startBBBB;
    double durationBBBB;
    startBBBB = std::clock();

        for (int i=0; i<nBBBB; i++){
            TreeBBBB.better_find(rand());
        }

    durationBBBB = ( std::clock() - startBBBB ) / (double) CLOCKS_PER_SEC;
    
    /// BALANCING THE TREES ///
    
    Treeb.better_balance();
    
    TreeB.better_balance();
    
    TreeBB.better_balance();
    
    TreeBBB.better_balance();
    
    TreeBBBB.better_balance();
    
    
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
    
    
    std::clock_t Bal_startBBB;
    double Bal_durationBBB;
    Bal_startBBB = std::clock();

        for (int i=0; i<nBBB; i++){
            TreeBBB.better_find(rand());
        }

    Bal_durationBBB = ( std::clock() - Bal_startBBB ) / (double) CLOCKS_PER_SEC;
    
    std::clock_t Bal_startBBBB;
    double Bal_durationBBBB;
    Bal_startBBBB = std::clock();

        for (int i=0; i<nBBBB; i++){
            TreeBBBB.better_find(rand());
        }

    Bal_durationBBBB = ( std::clock() - Bal_startBBBB ) / (double) CLOCKS_PER_SEC;
    
    
    std::vector<double> v;
    
    v.push_back(durationb/nb);
    v.push_back(durationB/nB);
    v.push_back(durationBB/nBB);
    v.push_back(durationBBB/nBBB);
    v.push_back(durationBBBB/nBBBB);
    
    v.push_back(Bal_durationb/nb);
    v.push_back(Bal_durationB/nB);
    v.push_back(Bal_durationBB/nBB);
    v.push_back(Bal_durationBBB/nBBB);
    v.push_back(Bal_durationBBBB/nBBBB);


    std::ofstream outFile("Integer_comparison.txt");
  
    for (const auto &e : v) outFile << e << "\n";
    outFile << nb << "\n";
    outFile << nB << "\n";
    outFile << nBB << "\n";
    outFile << nBBB << "\n";
    outFile << nBBBB << "\n";
    
    
    
    
    /// PRINTING THE RESULTS
    
    std::cout<<"Spent time for finding in b: "<< durationb <<std::endl;
    std::cout<<"Spent time for finding in B: "<< durationB <<std::endl;
    std::cout<<"Spent time for finding in BB: "<< durationBB <<std::endl;
    std::cout<<"Spent time for finding in BBB: "<< durationBBB <<std::endl;
    std::cout<<"Spent time for finding in BBB: "<< durationBBBB <<std::endl;
    std::cout<<"Spent time for finding in balanced b: "<< Bal_durationb <<std::endl;
    std::cout<<"Spent time for finding in balanced B: "<< Bal_durationB <<std::endl;
    std::cout<<"Spent time for finding in balanced BB: "<< Bal_durationBB <<std::endl;
    std::cout<<"Spent time for finding in balanced BBB: "<< Bal_durationBBB <<std::endl;
    

    }
