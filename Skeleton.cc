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
  Node* parent;
  Node(const key_type  k, const value_type  v, Node* p = nullptr)  : value{v}, key{k}, parent{p}, left{nullptr}, right{nullptr} {}
 
  };
  
  
    std::unique_ptr<Node> root;
  
  public:
  BST() : root{nullptr} {};
   ~ BST (){}
  void insert (const key_type  k, const value_type  v);
  void print() const;
  void clear() const;
  void balance();
  void erase();
  
   /*std::unique_ptr<Node> operator=(const Node* m) {
    if (m != this) {
        this -> left = m -> left;
        this -> right = m -> right;
        this -> parent = m -> parent;
        this -> key = m -> key;
        this -> value = m-> value;
        
      }
    
    return *this;
    }
    */
  
  class Iterator;
  
 
  
  
  Iterator begin() 
  {Node* first_key = root.get();
  while(first_key -> left.get()){
  first_key = first_key -> left.get();
  };
  std::cout <<"sono qui "<< first_key -> key <<std::endl;
  return Iterator{first_key, root.get()};
  }
  Iterator end() { 
  Node* last_key = root.get();
  while(last_key -> right.get()){
  last_key = last_key -> right.get();
  };
  std::cout <<"sono qui "<< last_key -> key <<std::endl;
  return Iterator{last_key, root.get()};
   }

  class ConstIterator;
  ConstIterator cbegin() const { 
  Node* first_key = root.get();
  while(first_key -> left.get()){
  first_key = first_key -> left.get();
  };
  std::cout <<"sono qui "<< first_key -> key <<std::endl;
  return ConstIterator{first_key, root.get()}; }
  
  ConstIterator cend() const {
  Node* last_key = root.get();
  while(last_key -> right.get()){
  last_key = last_key -> right.get();
  };
  std::cout <<"sono qui "<< last_key -> key <<std::endl;
  return ConstIterator{last_key, root.get()};
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

class BST<key_type, value_type>::Iterator  {
  using Node = BST<key_type, value_type>::Node;
  Node* current;
  Node* _root;

 public:
  Iterator(Node* n, Node* root) : current{n}, _root{root} {};
  value_type& operator*() const { return current->key; } /// VALUEEEE

  // ++it
  Iterator& operator++() {
    Node* last = _root;
    while(last -> right){
    last = last -> right.get();
    }
    if (current == last){
    //std::cout << "ci passo" << std::endl;
    return *this;
    }
    else if(current -> right.get() == nullptr && current -> parent -> right.get() == current){
    current = current -> parent -> parent;
    }
    else if(current -> right.get() == nullptr && current -> parent -> left.get() == current){ 
    current = current -> parent;
    }
    else if(current -> right.get() != nullptr){
    current = current -> right.get();
    while(current -> left.get()){
    current = current -> left.get();
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
  using parents = BST<key_type,value_type> ::Iterator;

 public:
  using parents::Iterator;
};

/*
template < typename key_type, typename value_type>
 Iterator<key_type,value_type>::begin(){ 
  
  Node* first_key = root.get();4 4

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
    temp -> left.reset(new Node{k,v, temp});
   std::cout << temp -> left -> parent -> key << " " << temp -> key << std::endl;
    }
    
    else{
    std::cout << "NUOVO NODO DESTRA" << std::endl;
    temp -> right.reset(new Node{k,v, temp});
    std::cout << temp -> right -> parent -> key << " " << temp -> key << std::endl;
    } 
    return;
    };
    
    

template <typename key_type, typename value_type>
void BST<key_type, value_type>::print() const {


  auto it {this->cbegin()};
  auto it_end{this->cend()};
  for (; it != ++it_end; ++it){
    std::cout << *it << " ";}
    std::cout << *it_end << std::endl;
}   

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
  Tree.insert(8,2);
  Tree.insert(5,2);
  Tree.insert(3,3);
  Tree.insert(7,3);
  Tree.insert(4,2);
  Tree.insert(14,1);
  Tree.insert(6,2);
  Tree.insert(9,2);
  Tree.insert(13,2);
  Tree.insert(15,2);
  Tree.insert(10,2);
  Tree.insert(20,2);
  Tree.insert(30,2);
  Tree.insert(16,2);
  Tree.print();
  BST<int, int>::Iterator first = Tree.begin();
  BST<int, int>::Iterator last = Tree.end();
  BST<int, int>::ConstIterator cfirst = Tree.cbegin();
  BST<int, int>::ConstIterator clast = Tree.cend();
  std::cout << "funziona lo scheletro" << std::endl;
  };






















 
