#ifndef CLASSBST
#define CLASSBST
#include<memory>


//class to compare


template < typename key_type >
class Greater
    {
        public:

            struct Compare_struct{
                bool operator()(const key_type& k1, const key_type& k2){
                return k1 > k2;
                }
            };

            bool compare ( const key_type& k1, const key_type& k2){return k1 > k2;}
};


template < typename key_type >
class Minor
    {
        public:

            struct Compare_struct{
                bool operator()(const key_type& k1, const key_type& k2){
                return k1 < k2;
                }
            };

            bool compare ( const key_type& k1, const key_type& k2){return k1 < k2;}
};







template < typename key_type, typename value_type, class Compare>
class BST {
  
    private:
    
    
        struct Node {
        
            key_type key;
            value_type value;
        
            Node* parent; //needed for Iterator
        
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
        void balance(); //first attempt
        void better_balance(); //second attempt, ricursively defined
        
        //needed for the balance()
        void BalancedTree(std::vector<std::pair<key_type, value_type>> array,int dim); 
        
        //needed for the better_balance()
        void Better_BalancedTree(int b1, int e1, int b2, int e2, const std::vector<std::pair<key_type, value_type>>& array);
  
        
        //recursive function needed for copy-constructor
        void CopyNode(Node* new_node, Node* old_node){
            
            if(old_node -> left){
                new_node -> left.reset( new Node(old_node -> left -> key, old_node -> left -> value, new_node));
                CopyNode(new_node -> left.get(), old_node -> left.get());
                }
            
            if(old_node -> right){
                new_node -> right.reset( new Node(old_node -> right -> key, old_node -> right -> value, new_node -> parent));
                CopyNode(new_node -> right.get(), old_node -> right.get());
                }    
            }
    
    
         // Copy-Constructor
        BST(const BST &other) { 
            root.reset(new Node(other.root -> key, other.root -> value));
            CopyNode(root.get(), other.root.get());
        }  
    
    
        // Move-Constructor
    
        BST( BST<key_type, value_type, Compare>&& other) {
            root = std::move(other.root);
            other.root.reset();
       }
    
        //Copy-Assignment
    
        BST& operator=(const BST<key_type, value_type, Compare>& other){

        if (this == &other) {
            return *this; 
            }
        
        if (root != nullptr){
            root.reset();
            }

        if (other.root != nullptr) {
            root.reset(new Node(other.root -> key, other.root -> value));
            CopyNode(root.get(), other.root.get());
            }
        
        return *this;
      }
    
    
        // Move - Assignment
        BST& operator=(BST<key_type, value_type, Compare>&& other){
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
        
        // Const
       const value_type& operator[](const key_type& k) {
        	auto it = find(k);
        	if (it != nullptr){
        	return it.current -> value;
        	}
        	else{
        	const value_type new_val{};
        	insert( k, new_val);
        	auto it = find(k);
        	return  it.current -> value;
        	}
        }
        
        Compare comp_func;
        typename Compare::Compare_struct compare_struct ;
        // it finds a key from the root  
        Iterator better_find(const key_type k){
            Node* next = root.get(); 
                if (root == nullptr){
    
                    return Iterator{nullptr}; 
                }
                else {
                    
                    while(next != nullptr && k != next -> key){
                        bool comp = compare_struct(k, next -> key); 
                        if(comp){
                            next = next -> left.get();
                        }
                        else if (!comp){
                            next = next -> right.get();
                            }   
                        }
                    }
                if(next == nullptr){
                    std::cout << "Key not found!" << std::endl;
                    return Iterator{nullptr}; 
                }
                return Iterator{next};
            }
  
       Iterator begin() {
        
            Node* first_key = root.get();
        
            while(first_key -> left.get()){
                 first_key = first_key -> left.get();
                };
        
                return Iterator{first_key};
            }
  
       Iterator end() { return Iterator{nullptr};} 
        
        //it finds a key from the smallest key to the largest one
       
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
            
    
            ConstIterator last() const { 
        
                Node* first_key = root.get();
        
                while(first_key -> right.get()){
                    first_key = first_key -> right.get();
                };
        
                std::cout<<"Last key: "<<first_key -> key<<"; Last value: "<<first_key -> value<<"."<<std::endl;
                return ConstIterator{first_key}; 
        
                }
       
};

#endif

