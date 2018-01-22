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



template < typename key_type, typename value_type>
void BST<key_type,value_type>::BalancedTree(std::vector<std::pair<key_type, value_type>> array,int dim){
    
    int mid {0};
    std::vector<int> indicator {};
    
    for (int i = 0; i != dim; ++i){
        indicator.push_back(1);
        };
    
    indicator.push_back(0);
    int sum_indicator = 1;
    std::vector<int> finder {};
    finder.push_back(1);
    finder.push_back(0);
    std::vector<int> indicatorjj1 {};
    indicatorjj1.push_back(0);
    indicatorjj1.push_back(0);
    
    while(sum_indicator!=0){
        int b{0};
        int e{0};
        int i{0};
        int j{0};
        while (indicator[i]==0){
            b++;
            i++;
            };
        while (indicatorjj1 != finder){
            e++;
            j++;            
            indicatorjj1[0] = indicator[j];
            indicatorjj1[1] = indicator[j+1];
            };
        
        indicatorjj1[0] = 0;
        indicatorjj1[1] = 0;
        
        mid = (b+e)/2;
        indicator[mid] = 0;
        sum_indicator = std::accumulate(indicator.begin(), indicator.end(), 0);
        insert((array[mid]).first,(array[mid]).second);
        };
    finder.clear();
    indicator.clear();
    indicatorjj1.clear();
    }






template < typename key_type, typename value_type>
void BST<key_type,value_type>::balance(){
    std::vector<std::pair<key_type, value_type>> arr {};
    auto it {this->cbegin()};
    auto it_end{this->cend()};
    int dim = 0;
    
    for ( ; it != it_end; ++it){
        arr.push_back(*it);
        dim = dim + 1;
        }
    root.reset();
    BalancedTree(arr, dim);

    
    }   
    
   

