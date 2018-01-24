#include <cstdlib>
#include <ctime>
#include <iostream>
#include <string>
#include <vector>
#include <numeric>

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
 std::vector<string> vec1 {};
 std::vector<string> vec2 {};
 
 std::clock_t start1;
 double duration1;
 double duration11;
 double duration22;
 double duration2;
 
 //Tree of 1000 elements
 
 
 for(int i = 0; i < 10000; i++){
 string prova = random_string(7);
 Tree.insert(prova, "aaaaaaaa");
 if(i%100 == 0){
 vec1.push_back(prova);
 }
 }
 
 start1 = clock();
 
 for(int i = 0; i < 100; i++){
 Tree.better_find(vec1[i]);
 }
 
 duration11 = (clock() -start1)/ (double) CLOCKS_PER_SEC;
 
 
 std::clock_t start2;
 
 
 //Tree of 10000 elements
 for(int i = 0; i < 100000; i++){
 string prova = random_string(7);
 Tree2.insert(prova, "aaaaaaaa");
 if(i%100 == 0){
 vec2.push_back(prova);
 }
 }
 
 start2 = clock();
 
 for(int i = 0; i < 1000; i++){
 Tree2.better_find(vec2[i]);
 }
 
 duration22 = (clock() -start2)/ (double) CLOCKS_PER_SEC;
 
 std::cout << "Find in Tree1 NOT BALANCED = " << duration11 << endl;
 std::cout << "Find in Tree2 NOT BALANCED = " << duration22 << endl;
 
 Tree.better_balance();
 Tree2.better_balance();
 
 start1 = clock();
 
 for(int i = 0; i < 100; i++){
 Tree.better_find(vec1[i]);
 }
 
 duration1 = (clock() -start1)/ (double) CLOCKS_PER_SEC;
 
 
 
 start2 = clock();
 
 for(int i = 0; i < 1000; i++){
 Tree2.better_find(vec2[i]);
 }
 
 duration2 = (clock() -start2)/ (double) CLOCKS_PER_SEC;
 
 std::cout << "Find in Tree1 NOT BALANCED = " << duration11 << endl;
 std::cout << "Find in Tree2 NOT BALANCED = " << duration22 << endl;
 
 std::cout << "Find in Tree1 BALANCED = " << duration1 << endl;
 std::cout << "Find in Tree2 BALANCED = " << duration2 << endl;
 }
 
 
 
