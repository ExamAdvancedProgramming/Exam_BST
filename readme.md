# BINARY SEARCH TREE

### What we have submitted
We have implemented the following files:

- **Class_BST.h** : here the class is implemented. 
- **Iterators_BST.h**: in this file you could find the algorithm for the iterator and some of its functions.
- **Functions_BST.h**: where some functions of the class are included.
- **Main_BST.cc**: where all the functions have been tested.
- **Integer_Lookup_comparison**: here the performance of the look-up strategy is checked on an *itegers* balanced BST.
- **String_Lookup_comparison**: here the performance of the look-up strategy is checked on an *strings* balanced BST.

### Checking the code
The Main_BST.cc has been checked successfully through `$valgrid`command and with the flags -Wall -Wextra.
We have also checked that the look-ups behave as `O(log N)` in balanced trees.

IMMAGINI

### Functions Implemented
The tree has the following functions:

      1. `insert (key, value)`: if the tree is empty, it creates a new pair key-value root. Otherwise, it appends a new key-value        
      node according to the comparison procedure. If the key value already exists, nothing happens.
      2. `print`,  used to print `key: value` of each node. Note that the output should be in order with respect to the keys.
      3. `clear()`, clear the content of the tree.
      4. `begin()`, return an `iterator` to the first node (which likely will not be the root node)
      5. `end()`, return a proper `iterator`
      6. `cbegin()`, return a `const_iterator` to the first node
      7. `cend()`, return a proper `const_iterator`
      8. `balance()`, balance the tree.
      9. `find`, find a given key and return an iterator to that node. If the key is not found returns `end()`;
      9. **optional** `erase`, delete the node with the given key.
      10. **optional** implement the `value_type& operator[](const key_type& k)` function int the `const` and `non-const` versions). This functions, should return a reference to the value associated to the key `k`. If the key is not present, a new node with key `k` is allocated having the value `value_type{}`. 

![](./.aux/binary.png)




  - implement a **template** binary search tree
    - it must be templated on the type of the key and the type of the value associated with it.
    - **optional** you can add a third template on the operation used to compare two different keys.
    - implement proper iterators for your tree (i.e., `iterator` and `const_iterator`)
    - the tree must have at least the following public member function
      1. `insert`, used to insert a new pair key-value.
      2. `print`,  used to print `key: value` of each node. Note that the output should be in order with respect to the keys.
      3. `clear()`, clear the content of the tree.
      4. `begin()`, return an `iterator` to the first node (which likely will not be the root node)
      5. `end()`, return a proper `iterator`
      6. `cbegin()`, return a `const_iterator` to the first node
      7. `cend()`, return a proper `const_iterator`
      8. `balance()`, balance the tree.
      9. `find`, find a given key and return an iterator to that node. If the key is not found returns `end()`;
      9. **optional** `erase`, delete the node with the given key.
      10. **optional** implement the `value_type& operator[](const key_type& k)` function int the `const` and `non-const` versions). This functions, should return a reference to the value associated to the key `k`. If the key is not present, a new node with key `k` is allocated having the value `value_type{}`. 

    - implement copy and move semantics for the tree.

- test the performance of the lookup (using the function `find`) before and after the tree is re-balanced. Use proper numbers (and types) of nodes and look-ups. Does lookup behaves as `O(log N)`?
- **optional** document the code with `Doxygen`
- write a short report
- test everything

### Hints
- you can use `std::pair<key_type,value_type>` found in the header `utility`
- use recursive functions
- **Big hint** start coding and using the iterators ASAP.

