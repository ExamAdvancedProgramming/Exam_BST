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
        Node(const key_type  k, const value_type  v, Node* p = nullptr) : value{v}, key{k}, parent{p}, left{nullptr}, right{nullptr} {}
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
  
  //FIND?? DOBBIAMO FARLO PER L'ESAME??
  
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

