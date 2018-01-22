#include <iostream>
#include <memory>
#include <utility>


template < typename key_type, typename value_type>
//std::pair<key_type, value_type> types;
class BST {
  
  private:
    struct Node {
        
        key_type key;
        value_type value;
        
        Node* parent;
        
        std::unique_ptr<Node> left;
        std::unique_ptr<Node> right;
        
        Node(const key_type  k, const value_type  v, Node* p = nullptr) : key{k}, value{v}, parent{p}, left{nullptr}, right{nullptr} {}
    
        // copy-constructor for the node
        Node(const Node& other) {
            value = other.value;
            key = other.key;
            parent = other.parent;
            left.reset(other.left.get());
            right.reset(other.right.get());
            }
    
    };
  
    std::unique_ptr<Node> root;
  
  
  public:
    BST() : root{nullptr} {};
     ~ BST (){}
    void insert (const key_type  k, const value_type  v);
    void print() const;
    void clear();
    void balance();
    void erase();
    void BalancedTree(std::vector<std::pair<key_type, value_type>> array,int dim);
  
    // Copy-Constructor
  
    BST(const BST &other) { 
    if (other.root == nullptr){
        root.reset();
    }
    root.reset(new Node(*(other.root)));
    }  
    
    // Move-Constructor
    
    BST( BST<key_type, value_type>&& other) {
    root = std::move(other.root);
    other.root.reset();
    }
    
    //Copy-Assignment.
    
    BST& operator=(const BST<key_type, value_type>& other){

      if (this == &other) {
        return *this; 
        }
        
      if (root != nullptr){
        root.reset();
        }

      if (other.root != nullptr) {
        root.reset(new Node(*(other.root)));
        }
        
      return *this;
      }
    
    
     // move assignment
    BST& operator=(BST<key_type, value_type>&& other){
      if (root != nullptr){
            root.reset();
         }
         
      if (other.root != nullptr){
         root = std::move(other.root);
         other.root.reset();
      }

      return *this;
    }  
  
  
    class Iterator;
  
    Iterator begin() {
        
        Node* first_key = root.get();
        
        while(first_key -> left.get()){
            first_key = first_key -> left.get();
        };
        
        return Iterator{first_key};
    }
  
    Iterator end() { return Iterator{nullptr};} 
        
        
    Iterator find(key_type key) const{
        auto it {this -> cbegin()};
        auto it_end {this -> cend()};
        
        for (; it != it_end; ++it){
            key_type comp = (*it).first;
            if (comp == key ){
                return it;
                }
            }
        std::cout << "The key " << key << " is not in the tree..." << std::endl;
        return it_end;
        }
        

    class ConstIterator;
    
    ConstIterator cbegin() const { 
        
        Node* first_key = root.get();
        
        while(first_key -> left.get()){
            first_key = first_key -> left.get();
        };
        
        return ConstIterator{first_key}; 
        
        }
  
    ConstIterator cend() const { return ConstIterator{nullptr}; }
       
  
    value_type& operator[](key_type const &k) const {
    //ritorna una reference al valore relativo alla key
    //VERSIONE CONST 
    };

  value_type& operator[](key_type const &k) {
    //ritorna una reference al valore relativo alla key 
    };
};

