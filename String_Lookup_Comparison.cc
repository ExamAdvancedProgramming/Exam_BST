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

string random_string(int l, std::string charIndex = "abcdefghijklmnaoqrstuvwxyz"){
int randomIndex;
std::string rs = "";

for (int i = 0; i < l; ++i) {
    randomIndex = rand() % charIndex.length();
    rs += charIndex[randomIndex];
}

return rs;

}
 
 int main(){
 
 BST<string, string> Tree{};
 BST<string, string> Tree2{};
 BST<string, string> Tree3{};
 int nb = 100000;
 int nB = 500000;
 int nBB = 1000000;
 int l = 6;
 
 std::clock_t start1;

 double duration1;
 double duration2;
 double duration3;
 
 
 double duration1_bal;
 double duration2_bal;
 double duration3_bal;
 
 //Tree of 1000 elements
 
 
 for(int i = 0; i < nb; i++){
 Tree.insert(random_string(l), "aaaa");
 
 }
 
 start1 = clock();
 
 for(int i = 0; i < nb; i++){
 Tree.better_find(random_string(l));
 }
 
 duration1 = (clock() -start1)/ (double) CLOCKS_PER_SEC;
 
 
 std::clock_t start2;
 
 
 //Tree of 10000 elements
 for(int i = 0; i < nB; i++){
 Tree2.insert(random_string(l), "aaaa");
 }
 
 start2 = clock();
 
 for(int i = 0; i < nB; i++){
 Tree2.better_find(random_string(l));
 }
 
 duration2 = (clock() -start2)/ (double) CLOCKS_PER_SEC;
 
 std::clock_t start3;
 
 
 //Tree of 1000000 elements
 for(int i = 0; i < nBB; i++){
 Tree3.insert(random_string(l), "aaaa");
 }
 
 start3 = clock();
 
 for(int i = 0; i < nBB; i++){
 Tree3.better_find(random_string(l));
 }
 
 duration3 = (clock() -start2)/ (double) CLOCKS_PER_SEC;
 
 
 
 Tree.better_balance();
 Tree2.better_balance();
 Tree3.better_balance();
 
 start1 = clock();
 
  
 for(int i = 0; i < nb; i++){
 Tree.better_find(random_string(l));
 }
 
 duration1_bal = (clock() -start1)/ (double) CLOCKS_PER_SEC;
 
 
 
 start2 = clock();
 
   
 for(int i = 0; i < nB; i++){
 Tree2.better_find(random_string(l));
 }
 
 duration2_bal = (clock() -start2)/ (double) CLOCKS_PER_SEC;
 
 start3 = clock();
 
   
 for(int i = 0; i < nBB; i++){
 Tree3.better_find(random_string(l));
 }
 
 duration3_bal = (clock() -start3)/ (double) CLOCKS_PER_SEC;
 
 std::cout << "Find in Tree1 NOT BALANCED = " << duration1 << endl;
 std::cout << "Find in Tree2 NOT BALANCED = " << duration2 << endl;
 std::cout << "Find in Tree3 NOT BALANCED = " << duration3 << endl;
 
 std::cout << "Find in Tree1 BALANCED = " << duration1_bal << endl;
 std::cout << "Find in Tree2 BALANCED = " << duration2_bal << endl;
 std::cout << "Find in Tree3 BALANCED = " << duration3_bal << endl;
 
 std::cout<<"Comparison between times: log(n)/log(N) = " << log10(nb)/log10(nB) << ";  " << "Tb/TB = "<< duration1/duration2 << "." << std::endl;
 }
 
 
 
