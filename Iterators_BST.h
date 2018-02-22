#ifndef ITERATORSBST
#define ITERATORSBST


template < typename key_type, typename value_type, class Compare>

class BST<key_type, value_type, Compare>::Iterator {
    private:
        using Node = BST<key_type, value_type, Compare>::Node;
        
        
    public:
    	Node* current; //needed public for operator[]
        Iterator(Node* n) : current{n} {};
        std::pair<key_type&, value_type&> operator*() const { return {current -> key, current -> value}; }

         // ++iterator definition
  
        Iterator& operator++() {
       
            if(current -> right.get() != nullptr){
                current = current -> right.get();
                while(current -> left.get()){
                    current = current -> left.get();
                }
            }
            else{
                current = current -> parent;
            }
            return *this;
            }
  
  

        bool operator==(const Iterator& other) {
            return this->current == other.current;
        }
  
        bool operator!=(const Iterator& other) { return !(*this == other); }

};

template < typename key_type, typename value_type, class Compare>
class BST<key_type,value_type, Compare> ::ConstIterator : public BST<key_type,value_type, Compare> ::Iterator {
     
        using parent = BST<key_type,value_type, Compare> ::Iterator;

     public:
       using parent::Iterator;
       const std::pair<const key_type&, const value_type&> operator*() const { 
       return {this -> current -> key, this -> current -> value}; }
       
    };
    
#endif
