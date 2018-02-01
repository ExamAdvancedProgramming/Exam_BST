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
                std::cout << "Node " << k << " already exists"<< std::endl;
               
                return;
                }
            }
        }
    if (k < temp -> key){
        temp -> left.reset(new Node{k,v, temp});
        std::cout << "Node left " << std::endl;
        }
    else{
        temp -> right.reset(new Node{k,v, temp -> parent});
        std::cout << "Node right "  << std::endl;
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



template < typename key_type, typename value_type>
<<<<<<< HEAD
void BST<key_type,value_type>::Better_BalancedTree(int b1, int e1, int b2, int e2, const std::vector<std::pair<key_type, value_type>>& array){
=======
void BST<key_type,value_type>::Better_BalancedTree(int b1, int e1, int b2, int e2, const std::vector<std::pair<key_type, value_type>> &array){
>>>>>>> 2c63d18c625b25af557107202ed424b402b39cb3
    
    if (b1 <= e1){
    
    int mid1 = (b1 + e1)/2;
    
    insert((array[mid1]).first, (array[mid1]).second);
    Better_BalancedTree(b1, mid1 -1, mid1 +1, e1, array);
    
    };
    if (b2 <= e2 && b2 != b1){
    
    int mid2 = (b2 + e2)/2;
    
    insert((array[mid2]).first, (array[mid2]).second);
    Better_BalancedTree(b2, mid2 -1, mid2 +1, e2, array);
    
    };
   
}


    
    
template < typename key_type, typename value_type>
void BST<key_type,value_type>::better_balance(){
    std::vector<std::pair<key_type, value_type>> arr {};
    auto it {this->cbegin()};
    auto it_end{this->cend()};
    int dim = -1;
    
    for ( ; it != it_end; ++it){
        arr.push_back(*it);
        dim = dim + 1;
<<<<<<< HEAD
=======
        
       // std::cout << (arr[dim]).first << " " << dim << std::endl;
>>>>>>> 2c63d18c625b25af557107202ed424b402b39cb3
        }
    
    int mid = (dim)/2;
    root.reset();
    insert((arr[mid]).first, (arr[mid]).second);
    
    std::cout << "Start Balancing..." << std::endl;
    
    Better_BalancedTree(0, mid -1, mid +1, dim, arr);

    
    }  

   

