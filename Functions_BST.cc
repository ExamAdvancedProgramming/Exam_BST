//#include "Iterators_BST.cc"


template < typename key_type, typename value_type>
void BST<key_type,value_type>::insert(const key_type k, const value_type v){
     Node* temp {nullptr};
     if (root == nullptr){
        root.reset(new Node{k,v});
        
        return; 
     }
     else {
        Node* next = root.get(); 
        while(next){
            if(k < next -> key){
               temp = next; 
               next = next -> left.get();
            }
            else if (k > next -> key){
                temp = next;
                next = next -> right.get();
            }
            else {
                std::cout << "this key already exists!" << std::endl;
                return;
                }
            }       
    
        }
    if (k < temp -> key){
        temp -> left.reset(new Node{k,v, temp});
        std::cout << "Left node inserted with key " << temp -> left -> key << std::endl;
        }
    
    else{
        temp -> right.reset(new Node{k,v, temp});
        std::cout << "Right node inserted with key " << temp -> right -> key << std::endl;
        } 
    
    return;
    
    };
    
template <typename key_type, typename value_type>
void BST<key_type, value_type>::print() const {
  
  if (!root){
    std::cout << "The Tree is empty!" << std::endl; 
  }
  else{
    auto it {this->cbegin()};
    auto it_end{this->cend()};
  
    for (; it != ++it_end; ++it){
        std::cout << "["<< !it << " : "<< *it << "]; ";
        }
    std::cout << "["<< !it_end << " : " << *it_end << "]. "<< std::endl;
    }
    
 }
 
template <typename key_type, typename value_type>
void BST<key_type, value_type>::clear() {
    
    if(root){
       
       root.reset();
    
    }
    
}      
    

