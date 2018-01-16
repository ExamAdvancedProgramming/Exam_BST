//#include "Iterators_BST.cc"


template < typename key_type, typename value_type>
void BST<key_type,value_type>::insert(const key_type k, const value_type v){
    Node* temp {nullptr};
    if (root == nullptr){
        root.reset(new Node{k,v});
        std::cout << "New root node key " << root -> key << std::endl;
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
                std::cout << "This key already exists!" << std::endl;
                return;
                }
            }
        }
    if (k < temp -> key){
        temp -> left.reset(new Node{k,v, temp});
        std::cout << "New left node key " << temp -> left -> key << std::endl;
        }
    else{
        temp -> right.reset(new Node{k,v, temp -> parent});
        std::cout << "New right node key " << temp -> right -> key << std::endl;
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
        
        for (; it != it_end; ++it){
            std::cout << "[" << (*it).first << " : " << (*it).second << "] " ;
            }
        std::cout << "." << std::endl;
        }
    }


 
template <typename key_type, typename value_type>
void BST<key_type, value_type>::clear() {
    
    if(root){
       
       root.reset();
    
    }
    
}      
    
   

