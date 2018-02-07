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




using namespace std;

string random_string(int l, std::string charIndex = "abcdefghijklmnaoqrstuvwxyz0123456789"){
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
 BST<string, string> Tree4{};
 BST<string, string> Tree5{};
 
 
 int nb = 10000;
 int nB = 100000;
 int nBB = 1000000;
 int nBBB = 10000000;
 int nBBBB = 30000000;
 
 int l = 6;
 
 std::clock_t start1;

 double duration1;
 double duration2;
 double duration3;
 double duration4;
 double duration5;
 
 
 double duration1_bal;
 double duration2_bal;
 double duration3_bal;
 double duration4_bal;
 double duration5_bal;
 
 //Tree of nb elements
 
 
 for(int i = 0; i < nb; i++){
 Tree.insert(random_string(l), "aaaa");
 
 }
 
 start1 = clock();
 
 for(int i = 0; i < nb; i++){
 Tree.better_find(random_string(l));
 }
 
 duration1 = (clock() -start1)/ (double) CLOCKS_PER_SEC;
 
 
 std::clock_t start2;
 
 
 //Tree of nB elements
 for(int i = 0; i < nB; i++){
 Tree2.insert(random_string(l), "aaaa");
 }
 
 start2 = clock();
 
 for(int i = 0; i < nB; i++){
 Tree2.better_find(random_string(l));
 }
 
 duration2 = (clock() -start2)/ (double) CLOCKS_PER_SEC;
 
 std::clock_t start3;
 
 
 //Tree of nBB elements
 for(int i = 0; i < nBB; i++){
 Tree3.insert(random_string(l), "aaaa");
 }
 
 start3 = clock();
 
 for(int i = 0; i < nBB; i++){
 Tree3.better_find(random_string(l));
 }
 
 duration3 = (clock() -start3)/ (double) CLOCKS_PER_SEC;
 
 
  std::clock_t start4;
 
 //Tree of nBBB elements
 
 for(int i = 0; i < nBBB; i++){
 Tree4.insert(random_string(l), "aaaa");
 }
 
 start4 = clock();
 
 for(int i = 0; i < nBBB; i++){
 Tree4.better_find(random_string(l));
 }
 
 duration4 = (clock() -start4)/ (double) CLOCKS_PER_SEC;
 

  std::clock_t start5;
 
 //Tree of nBBBB elements
 
 for(int i = 0; i < nBBBB; i++){
 Tree5.insert(random_string(l), "aaaa");
 }
 
 start5 = clock();
 
 for(int i = 0; i < nBBBB; i++){
 Tree5.better_find(random_string(l));
 }
 
 duration5 = (clock() -start5)/ (double) CLOCKS_PER_SEC;
 
 
 
 Tree.better_balance();
 Tree2.better_balance();
 Tree3.better_balance();
 Tree4.better_balance();
 Tree5.better_balance();
 
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
 
 
start4 = clock();
 
   
 for(int i = 0; i < nBBB; i++){
 Tree4.better_find(random_string(l));
 }
 
 duration4_bal = (clock() -start4)/ (double) CLOCKS_PER_SEC;
 
 

start5 = clock();
 
   
 for(int i = 0; i < nBBBB; i++){
 Tree5.better_find(random_string(l));
 }
 
 duration5_bal = (clock() -start5)/ (double) CLOCKS_PER_SEC;
 
 std::vector<double> v;
 
 v.push_back(duration1/nb);
 v.push_back(duration2/nB);
 v.push_back(duration3/nBB);
 v.push_back(duration4/nBBB);
 v.push_back(duration5/nBBBB);
 
 v.push_back(duration1_bal/nb);
 v.push_back(duration2_bal/nB);
 v.push_back(duration3_bal/nBB);
 v.push_back(duration4_bal/nBBB);
 v.push_back(duration5_bal/nBBBB);


std::ofstream outFile("String_comparison.txt");
    // the important part
    for (const auto &e : v) outFile << e << "\n";
    outFile << nb << "\n";
    outFile << nB << "\n";
    outFile << nBB << "\n";
    outFile << nBBB << "\n";
    outFile << nBBBB << "\n";
 
 
 
 std::cout << "Find in Tree1 NOT BALANCED = " << duration1 << endl;
 std::cout << "Find in Tree2 NOT BALANCED = " << duration2 << endl;
 std::cout << "Find in Tree3 NOT BALANCED = " << duration3 << endl;
 std::cout << "Find in Tree4 NOT BALANCED = " << duration4 << endl;
 std::cout << "Find in Tree5 NOT BALANCED = " << duration5 << endl;
 
 std::cout << "Find in Tree1 BALANCED = " << duration1_bal << endl;
 std::cout << "Find in Tree2 BALANCED = " << duration2_bal << endl;
 std::cout << "Find in Tree3 BALANCED = " << duration3_bal << endl;
 std::cout << "Find in Tree4 BALANCED = " << duration4_bal << endl;
 std::cout << "Find in Tree5 BALANCED = " << duration5_bal << endl;
 
 
 std::cout<<"Comparison between times: log(n)/log(N) = " << log10(nb)/log10(nB) << ";  " << "(Tb/nb)/(TB/nB) = "<< (duration1/nb)/(duration2/nB) << "." << std::endl;
 
 
 }
 
 
 
