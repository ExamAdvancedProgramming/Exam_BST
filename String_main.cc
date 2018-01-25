#include <cstdlib>
#include <ctime>
#include <iostream>
#include <string>
#include <vector>
#include <numeric>
#include <math.h>

// Files needed

#include "Class_BST.cc"
#include "Iterators_BST.cc"
#include "Functions_BST.cc"




using namespace std;

string random_string(int l, std::string charIndex = "abcdefghijklmnaoqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890"){
int randomIndex;
std::string rs = "";

for (uint i = 0; i < l; ++i) {
    randomIndex = rand() % charIndex.length();
    rs += charIndex[randomIndex];
}

return rs;

}
 
 int main(){
 
 BST<string, string> Tree{};
 BST<string, string> Tree2{};
 int nb = 1000;
 int nB = 3000;
 
 std::clock_t start1;
 double duration1;
 double duration11;
 double duration22;
 double duration2;
 
 //Tree of 1000 elements
 
 
 for(int i = 0; i < nb; i++){
 Tree.insert(random_string(4), "aaaaaaaa");
 
 }
 
 start1 = clock();
 
 for(int i = 0; i < nb; i++){
 Tree.better_find(random_string(4));
 }
 
 duration11 = (clock() -start1)/ (double) CLOCKS_PER_SEC;
 
 
 std::clock_t start2;
 
 
 //Tree of 10000 elements
 for(int i = 0; i < nB; i++){
 Tree2.insert(random_string(4), "aaaaaaaa");
 }
 
 start2 = clock();
 
 for(int i = 0; i < nB; i++){
 Tree2.better_find(random_string(4));
 }
 
 duration22 = (clock() -start2)/ (double) CLOCKS_PER_SEC;
 
 std::cout << "Find in Tree1 NOT BALANCED = " << duration11 << endl;
 std::cout << "Find in Tree2 NOT BALANCED = " << duration22 << endl;
 
 Tree.better_balance();
 Tree2.better_balance();
 
 start1 = clock();
 
  
 for(int i = 0; i < nb; i++){
 Tree.better_find(random_string(4));
 }
 
 duration1 = (clock() -start1)/ (double) CLOCKS_PER_SEC;
 
 
 
 start2 = clock();
 
   
 for(int i = 0; i < nB; i++){
 Tree.better_find(random_string(4));
 }
 
 duration2 = (clock() -start2)/ (double) CLOCKS_PER_SEC;
 
 std::cout << "Find in Tree1 NOT BALANCED = " << duration11 << endl;
 std::cout << "Find in Tree2 NOT BALANCED = " << duration22 << endl;
 
 std::cout << "Find in Tree1 BALANCED = " << duration1 << endl;
 std::cout << "Find in Tree2 BALANCED = " << duration2 << endl;
 
 std::cout<<"Comparison between times: log(n)/log(N) = " << log10(nb)/log10(nB) << ";  " << "Tb/TB = "<< duration1/duration2 << "." << std::endl;
 }
 
 
 
