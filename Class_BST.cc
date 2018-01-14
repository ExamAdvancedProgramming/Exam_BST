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
        return Iterator{first_key, root.get()};
    }
  
    Iterator end() { 
        Node* last_key = root.get();
        while(last_key -> right.get()){
            last_key = last_key -> right.get();
        };
        return Iterator{last_key, root.get()};
        }
        
    Iterator find(key_type key) const{
    auto it {this -> cbegin()};
    auto it_end {this -> cend()};
    for (; it != it_end; ++it){
        key_type comp = !it;
        if (comp == key ){
            std::cout << !it << std::endl;
            return it;
            }
        }
    key_type comp = !it_end;    
    if ( comp == key ){
            std::cout << !it_end << std::endl;
            return it_end;
            }
    else{
    std::cout << "Key not found!" << std::endl;
        return Iterator{nullptr, root.get()};  //returns a null pointer and not cend()
    }
    }

    class ConstIterator;
    
    ConstIterator cbegin() const { 
        Node* first_key = root.get();
        while(first_key -> left.get()){
            first_key = first_key -> left.get();
        };
        return ConstIterator{first_key, root.get()}; }
  
    ConstIterator cend() const {
        Node* last_key = root.get();
        while(last_key -> right.get()){
            last_key = last_key -> right.get();
        };
        return ConstIterator{last_key, root.get()};
        }
  
  
    value_type& operator[](key_type const &k) const {
    //ritorna una reference al valore relativo alla key
    //VERSIONE CONST 
    };

  value_type& operator[](key_type const &k) {
    //ritorna una reference al valore relativo alla key 
    };
};

