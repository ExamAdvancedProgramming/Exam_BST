<<<<<<< HEAD
# BINARY SEARCH TREE
=======
# Binary Search Tree
>>>>>>> Sistemiamo

### What we have submitted
We have implemented the following files:

- **Class_BST.h** : here the class is implemented with its copy and move semantics. 
- **Iterators_BST.h**: in this file you could find the algorithm for the iterator and some of its functions.
- **Functions_BST.h**: where some functions of the class are included.
- **Main_BST.cc**: where all the functions have been tested.
- **Integer_Lookup_comparison.cc**: here the performance of the look-up strategy is checked on an *itegers* balanced BST.It also returns a text file named Integer_comparison.txt where a vector containing the results of the comparison is stored. 
- **String_Lookup_comparison.cc**: here the performance of the look-up strategy is checked on an *strings* balanced BST.It also returns a text file named String_comparison.txt where a vector containing the results of the comparison is stored.
- **png files** : two png files are contained in the folder. In each of them, the behaviour of searching times is reported and it is very close to log(n) as you can see in the "Checking the code" section.

### Checking the code
The Main_BST.cc has been checked successfully through `$valgrid`command and with the flags -Wall -Wextra.
We have also checked that the look-ups behave as `O(log N)` in balanced trees.

![](gatto.png)

### Functions Implemented
The tree has the following functions:

- `insert (key, value)`: if the tree is empty, it creates a new pair key-value root. Otherwise, it appends a new key-value node according to the comparison procedure. If the key value already exists, nothing happens;
- `print()`: all the couples, starting from the first key, are printed in order with respect to the keys;
- `clear()`: the whole tree is destroyed and a null-pointer is put as root;
- `begin()`: returns an `iterator` to the first node with respect to the keys;
- `end()`: returns a proper null-pointer `iterator`;
- `cbegin()`: a `const_iterator` to the first node is returned in order to only read the tree;
- `cend()`: returns a proper null-pointer `const-iterator`;
- `better_balance()`: it returns the root to a balanced tree. It is obtained by saving all the couples into a key-ordered vector and then inserting all the elements by the use of a recoursive function that takes mid-points of each sub-vector;
- `better_find(key)`: finds a given key and returns an iterator to that node. If the key is not found, a message `Key not found` is printed and then `end()` is returned. This function starts looking for the key from the root and for this reason it is very efficient.
- `find(key)`: finds a given key and returns an iterator to that node. If the key is not found, a message `Key not found` is printed and then `end()` is returned. This function starts looking for the key from the first node by the use of the iterator and for this reason it is not efficient.
- `last()`: we added this function that was not required because it seemed to be useful. In fact it returns an iterator to the last node and prints the last key-value couple.

### How to compile

There are three diffent ways to compile the codes:

- digit`make` to run main_BST.cc;
- digit`make integer` to run Integer_Lookup_comparison.cc;
- digit`make string` to run String_Lookup_comparison.cc.






