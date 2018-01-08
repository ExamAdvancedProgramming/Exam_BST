#include <iostream>
#include <memory>
#include <utility>


template < typename key_type, typename value_type>
//std::pair<key_type, value_type> types;
class BST {
  
  private:
  struct Node {
  value_type value;
  key_type key;
  std::unique_ptr<Node> left;
  std::unique_ptr<Node> right;
  std::unique_ptr<Node> parent;
  Node(const key_type  k, const value_type  v, Node* p = nullptr) : value{v}, key{k}, parent{p}, left{nullptr}, right{nullptr} {}
  };
  
  std::unique_ptr<Node> root;
  
  
  public:
  BST() : root{nullptr} {};
  void insert (const key_type  k, const value_type  v);
  void print() const;
  void clear() const;
  void balance();
  void erase();
  
  class Iterator;
  Iterator begin() { return Iterator{nullptr}; } //ritornare la chiave più piccola  
  Iterator end() { return Iterator{nullptr}; }

  class ConstIterator;
  ConstIterator cbegin() const { return ConstIterator{nullptr}; }
  ConstIterator cend() const { return ConstIterator{nullptr}; }
  
  Iterator find(key_type& k){
    //ritorna un iterator a nodo con quella key, altrimenti torna end()
};
  value_type& operator[](key_type const &k) const {
    //ritorna una reference al valore relativo alla key
    //VERSIONE CONST 
};

  value_type& operator[](key_type const &k) {
    //ritorna una reference al valore relativo alla key 
};
};

template < typename key_type, typename value_type>
class BST<key_type, value_type>::Iterator {
  using Node = BST<key_type, value_type>::Node;
  Node* current;

 public:
  Iterator(Node* n) : current{n} {}
  value_type& operator*() const { return current->value; }

  // ++it
  Iterator& operator++() {
    current = current->right.get();
    return *this;
  }

  // it++
  Iterator operator++(value_type ) {
    Iterator it {current};
    ++(*this);
    return it;
  }

  bool operator==(const Iterator& other) {
    return this->current == other.current;
  }
  bool operator!=(const Iterator& other) { return !(*this == other); }
};

template < typename key_type, typename value_type>

//template <typename types>
class BST<key_type,value_type> ::ConstIterator : public BST<key_type,value_type> ::Iterator {
  using parent = BST<key_type,value_type> ::Iterator;

 public:
  using parent::Iterator;
};

template < typename key_type, typename value_type>
void BST<key_type,value_type> ::insert(const key_type k, const value_type v){
     Node* temp {nullptr};
    if (root == nullptr){
    std::cout << "sono nullo" << std::endl;
    root.reset(new Node{k,v});
    return; 
    }
    else {
    std::cout << "non sono nullo" << std::endl;
    Node* next = root.get(); 
    while(next){
    std::cout << next -> key << std::endl;
    //temp -> parent = std::move(temp);
    if(k < next -> key){
    std::cout << "left!" << std::endl;
    temp = next; 
    next = next -> left.get();
    }
    else if (k > next -> key){
    std::cout << "right!" << std::endl;
    temp = next;
    next = next -> right.get();
    
    //std::cout  << next.key << std::endl;
    
    
    }
    else {
    std::cout << "this key already exists!" << std::endl;
    return;
    }
    
    
    }
    
     }
    std::cout << "fuori dal while" << std::endl; 
    if (k < temp -> key){
    std::cout << "NUOVO NODO SINISTRA" << std::endl;
    temp -> left.reset(new Node{k,v});
    }
    
    else{
    std::cout << "NUOVO NODO DESTRA" << std::endl;
    temp -> right.reset(new Node{k,v});
    } 
    return;
    };
    
/*if (root.get() == nullptr){
    std::cout << "sono nullo" << std::endl;
    root.reset(new Node{k,v});
    return; }
else { std::cout << "non sono nullo" << std::endl; 
std::cout << k << " " << curr -> key << std::endl;

/// questo forse e' meglio esterno....
    if (k == curr -> key && v == curr -> value){
    std::cout << "This node already exists!" << std::endl;
    }
    else if ( k == curr -> key){
    curr -> value = v;
    std::cout << "Key overwritten!" << std::endl;
    };
    
    
    bool control = true;
    while (control){
    while(k < curr -> key){
    std::cout << "non dovrei entrare qui dentro" << std::endl;
    curr = curr -> left.get();
    };
    if (curr -> right.get() != nullptr){
    curr = curr -> right.get(); }
    else{
 control = false;};
    };
    
    // forse è meglio se fai una funzione esterna...
    
};
//else if (k > curr -> key){
//curr = curr ->right.get();};    
*/



int main() {
  BST<int, int> Tree{};
  Tree.insert(2,2);
  //Tree.insert(2,2);
  Tree.insert(4,3);
  Tree.insert(3,3);
  Tree.insert(2,2);
  Tree.insert(1,1);
  Tree.insert(5,2);
  Tree.insert(6,2);
  std::cout << "funziona lo scheletro" << std::endl;
  };






















 
