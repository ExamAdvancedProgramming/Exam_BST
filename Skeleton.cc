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
  Node(const key_type  k, const value_type  v, Node * p = nullptr)  : value{v}, key{k}, parent{p}, left{nullptr}, right{nullptr} { }
  
 
  };
  
  std::unique_ptr<Node> root;
  
  
  
  public:
  BST() : root{nullptr} {};
  void insert (const key_type  k, const value_type  v);
  void print() const;
  void clear() const;
  void balance();
  void erase();
  
   Node* operator=(const Node* m) {
    if (m != this) {
        this -> left = m -> left;
        this -> right = m -> right;
        this -> parent = m -> parent;
        this -> key = m -> key;
        this -> value = m-> value;
        
      }
    
    return *this;
    }
  
  class Iterator;
  
  Iterator begin() {Node* first_key = root.get();
  while(first_key -> left.get()){
  first_key = first_key -> left.get();
  };
  std::cout <<"sono qui "<< first_key -> key <<std::endl;
  return Iterator{first_key};
  }
  Iterator end() { 
  Node* last_key = root.get();
  while(last_key -> right.get()){
  last_key = last_key -> right.get();
  };
  std::cout <<"sono qui "<< last_key -> key <<std::endl;
  return Iterator{last_key};
   }

  class ConstIterator;
  ConstIterator cbegin() const { 
  Node* first_key = root.get();
  while(first_key -> left.get()){
  first_key = first_key -> left.get();
  };
  std::cout <<"sono qui "<< first_key -> key <<std::endl;
  return ConstIterator{first_key}; }
  
  ConstIterator cend() const {
  Node* last_key = root.get();
  while(last_key -> right.get()){
  last_key = last_key -> right.get();
  };
  std::cout <<"sono qui "<< last_key -> key <<std::endl;
  return ConstIterator{last_key};
   }
  
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
    if (current == root.get())          //RADICE
    { current = current -> right.get();
    while(current -> left.get()){
    current = current.left();
    }
    }
    if(current -> key < root -> key){
    if (current -> right.get() = nullptr){
    current = current -> parent.get();
    }
    else{
    current = current -> right.get();
    while(current -> left.get()){
    current = current.left();
    }
    }
    }
    //current = current->right.get();
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

/*
template < typename key_type, typename value_type>
 Iterator<key_type,value_type>::begin(){ 
  
  Node* first_key = root.get();
  while(first_key -> left.get()){
  first_key = first_key -> left.get();
  };
  std::cout <<"sono qui "<< first_key -> key <<std::endl;
  return Iterator{first_key};
  } 
*/

template < typename key_type, typename value_type>
void BST<key_type,value_type>::insert(const key_type k, const value_type v){
    Node* temp {nullptr};
    if (root == nullptr){
    std::cout << "sono nullo" << std::endl;
    root.reset(new Node{k,v});
    root -> parent.reset(nullptr);
    return; 
    }
    else {
    std::cout << "non sono nullo" << std::endl;
    Node* next = root.get(); 
    while(next){
    //std::cout << next -> key << std::endl;
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
    temp -> left -> parent.reset(new Node{temp -> key, temp -> value});
    std::cout << temp -> left -> parent -> key << " " << temp -> key  << std::endl;
    if(temp -> parent != nullptr){
    std::cout << "SONO TUO PADRE!" << std::endl;}
    }
    
    else{
    std::cout << "NUOVO NODO DESTRA" << std::endl;
    temp -> right.reset(new Node{k,v});
    temp -> right -> parent.reset(new Node{temp -> key, temp -> value});
    std::cout << temp -> right -> parent -> key << " " << temp -> key  << std::endl;
     if(temp -> parent != nullptr){
    std::cout << "SONO TUO PADRE!" << std::endl;}
    }
    };
    
    
    

/*
template < typename key_type, typename value_type>
Node* BST<key_type,value_type>::find_first (Node * root){

Node* first_key = root.get();
  while(first_key -> left.get()){
  first_key = first_key -> left.get();
  };
  std::cout <<"sono qui "<< first_key -> key <<std::endl;
  return first_key;

}
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
  BST<int, int>::Iterator first = Tree.begin();
  BST<int, int>::Iterator last = Tree.end();
  BST<int, int>::ConstIterator cfirst = Tree.cbegin();
  BST<int, int>::ConstIterator clast = Tree.cend();
  std::cout << "funziona lo scheletro" << std::endl;
  };






















 
