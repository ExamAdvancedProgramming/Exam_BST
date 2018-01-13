template < typename key_type, typename value_type>

class BST<key_type, value_type>::Iterator {
    private:
        using Node = BST<key_type, value_type>::Node;
        Node* current;
        Node* _root;

    public:
        Iterator(Node* n, Node* r) : current{n}, _root{r} {};
        value_type& operator*() const { return current->value; }
        key_type& operator!() const { return current->key; }

  // ++iterator definition
  
    Iterator& operator++() {
        Node* last = _root;
        while(last -> right){
            last = last -> right.get();
            }
        if (current == last){
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
        return *this;
        }
  
  // iterator++ definition
  
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
class BST<key_type,value_type> ::ConstIterator : public BST<key_type,value_type> ::Iterator {
     using parent = BST<key_type,value_type> ::Iterator;

     public:
        using parent::Iterator;
    };
