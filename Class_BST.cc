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

