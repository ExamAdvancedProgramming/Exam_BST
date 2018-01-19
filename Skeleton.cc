#include <iostream>
#include <memory>
#include <utility>
#include <vector>


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
  Node(const key_type  k, const value_type  v, Node* p = nullptr)  : value{v}, key{k}, parent{p}, left{nullptr}, right{nullptr} {}
 
  };
  
  
    std::unique_ptr<Node> root;
  
  public:
  
  
  class Iterator;
  
  BST() : root{nullptr} {};
   ~ BST (){}
  void insert (const key_type  k, const value_type  v);
  void print() const;
  void clear() const;
  void balance();
  void erase();
  
  
  
    Node* BalancedTree(std::vector<std::pair<key_type, value_type>> array,int dim){
    std::cout << "SONO IO" << std::endl;
    
    int b {0};
    int e {0};
    int mid {0};
    std::vector<int> indicator {};
    
    for (int i = 0; i != dim; ++i){
    indicator.push_back(1);
    };
    indicator.push_back(0);
    
    while(indicator!=0){
        if(mid!=dim){
            while ((array[b]).first==0){
                b++;
            };
            while ((array[e+1]).first != 0){
                e++
            };
            mid = (b+e)/2;
            indicator[mid] = 0;
            insert((array[mid]).first,(array[mid]).second);
        };
        else{
        return;
        };
    };
    
    return root.get();
    }
 
  
   /*std::unique_ptr<Node> operator=(const Node* m) {
    if (m != this) {
        this -> left = m -> left;
        this -> right = m -> right;
        this -> parent = m -> parent;
        this -> key = m -> key;
        this -> value = m-> value;
        
      }
    
    return *this;
    }
    */
  

  
 
  
  
  Iterator begin() 
  {Node* first_key = root.get();
  while(first_key -> left.get()){
  first_key = first_key -> left.get();
  };
  //std::cout <<"sono qui "<< first_key -> key <<std::endl;
  return Iterator{first_key};
  }
  Iterator end() { 
  //Node* last_key = root.get();
  //while(last_key -> right.get()){
  //last_key = last_key -> right.get();
  //};
  //std::cout <<"sono qui "<< last_key -> key <<std::endl;
  return Iterator{nullptr};
   }

  class ConstIterator;
  ConstIterator cbegin() const { 
  Node* first_key = root.get();
  while(first_key -> left.get()){
  first_key = first_key -> left.get();
  };
  std::cout <<"sono iniziale "<< first_key -> key <<std::endl;
  return ConstIterator{first_key}; }
  
  ConstIterator cend() const {
  //Node* last_key = root.get();
  //while(last_key -> right.get()){
  //last_key = last_key -> right.get();
  //};
  //std::cout <<"Sono it finale "<< last_key -> key <<std::endl;
  return ConstIterator{nullptr};
   }
  
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

template < typename key_type, typename value_type>

class BST<key_type, value_type>::Iterator  {
  using Node = BST<key_type, value_type>::Node;
  Node* current;
  //Node* _root;

 public:
  Iterator(Node* n) : current{n} {};
  std::pair<key_type, value_type> operator*() const { return std::make_pair(current -> key, current -> value); }


  // ++it
  Iterator& operator++() {
    if(current -> right.get() != nullptr){
            //std::cout << "Ma ci passo qui3?" << std::endl;
            current = current -> right.get();
            while(current -> left.get()){
                current = current -> left.get();
                }
                }
    else{
    current = current -> parent;
    }
            
        //std::cout << "SONO CURRENT " << current -> key << std::endl; 
        //Node* last = _root;
        //while(last -> right){
          //  last = last -> right.get();
           // }
        //if (current == last){
          //  std::cout << "Ma ci passo qui5?" << std::endl;
           // return *this;
        //}
        /*
        if(current -> right.get() == nullptr && current -> parent -> right.get() == current){
            Node* temp = current;
           while(temp -> parent != nullptr){
            if (temp -> parent -> right.get() == temp){ 
               std::cout << "SONO 4 " << current -> key << std::endl;
              temp = temp -> parent; 
           }
           else{
           break;
           }
           }
           if (temp -> parent == nullptr){
            std::cout << "Ma ci passo qui1?" << std::endl;
            current = nullptr;//current -> parent -> parent;
            }
            else{
            current = current -> parent -> parent;
            }
            }
        else if(current -> right.get() == nullptr && current -> parent -> left.get() == current){ 
            std::cout << "Ma ci passo qui2?" << std::endl;
            current = current -> parent;
            }
        else if(current -> right.get() != nullptr){
            std::cout << "Ma ci passo qui3?" << std::endl;
            current = current -> right.get();
            while(current -> left.get()){
                current = current -> left.get();
                }
            }
        //else if(current == nullptr){
        //std::cout << "Ma ci passo qui4?" << std::endl;
          //  Iterator IT = Iterator {nullptr, _root};
           // return IT;
        //}
         */   
        return *this;
        }
    //Node* last = current;
    //Node* last = _root;
    /*while(last -> right){
    last = last -> right.get();
    }
    if (current == last){
    //std::cout << "ci passo" << std::endl;
    return *this;
    }
    */
    //std::cout << "SONO QUI 1 " << current -> key << std::endl;
    
    /*
    
    if(current -> right.get() == nullptr && current -> parent -> right.get() == current){
    
        while(last -> parent != nullptr){
            if (last -> parent -> parent -> right.get() == current -> parent){ 
      //          std::cout << "SONO QUI 2 " << current -> key << std::endl;
                last = last -> parent; 
            }
            else{
                std::cout << "SONO QUI 3 " << current -> key << std::endl;
                //break;//last -> parent = nullptr;
            }
            break;
       }
        if (last -> parent  == nullptr){
            std::cout << "SONO ULTIMO" << std::endl;
            //return ;
            }
        else{   
        current = current -> parent -> parent;
        }    
    }
    else if(current -> right.get() == nullptr && current -> parent -> left.get() == current){ 
    std::cout << "SONO QUI CASPITA: dx null e sono figlio sinitro" << current -> key << std::endl;
    current = current -> parent;
    
    }
    else if(current -> right.get() != nullptr){
    std::cout << "SONO QUI 4" << std::endl;
    current = current -> right.get();
    while(current -> left.get()){
    current = current -> left.get();
    }
    
    }*/
   //return *this;
    //current = current->right.get();
    

  // it++
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

//template <typename types>
class BST<key_type,value_type> ::ConstIterator : public BST<key_type,value_type> ::Iterator {
  using parents = BST<key_type,value_type> ::Iterator;

 public:
  using parents::Iterator;
};

/*
template < typename key_type, typename value_type>
 Iterator<key_type,value_type>::begin(){ 
  
  Node* first_key = root.get();4 4

  while(first_key -> left.get()){
  first_key = first_key -> left.get();
  };
  std::cout <<"sono qui "<< first_key -> key <<std::endl;
  return Iterator{first_key};
  } 
*/

template < typename key_type, typename value_type>
void BST<key_type,value_type>::insert(const key_type k, const value_type v){
    Node* temp {nullptr};
    if (root == nullptr){
    std::cout << "sono nullo" << std::endl;
    root.reset(new Node{k,v});
    return; 
    }
    else {
    std::cout << "non sono nullo" << std::endl;
    Node* next = root.get(); 
    while(next){
    std::cout << next -> key << std::endl;
    //temp -> parent = std::move(temp);
    if(k < next -> key){
    std::cout << "left!" << std::endl;
    temp = next; 
    next = next -> left.get();
    }
    else if (k > next -> key){
    std::cout << "right!" << std::endl;
    temp = next;
    next = next -> right.get();
    
    //std::cout  << next.key << std::endl;
    
    
    }
    else {
    std::cout << "this key already exists!" << std::endl;
    return;
    }
    
    
    }
    
     }
    std::cout << "fuori dal while" << std::endl; 
    if (k < temp -> key){
    std::cout << "NUOVO NODO SINISTRA" << std::endl;
    temp -> left.reset(new Node{k,v, temp});
   //std::cout << temp -> left -> parent -> key << " " << temp -> key << std::endl;
    }
    
    else{
    std::cout << "NUOVO NODO DESTRA" << std::endl;
    temp -> right.reset(new Node{k,v, temp -> parent});
    //std::cout << temp -> right -> parent -> key << " " << temp -> key << std::endl;
    } 
    return;
    };
    
    

template <typename key_type, typename value_type>
void BST<key_type, value_type>::print() const {

    std::cout << "HO INIZIATO A PRINTARE" << std::endl;
  if (!root){
    std::cout << "The Tree is empty!" << std::endl; 
  }
  else{
    auto it {this->cbegin()};
    auto it_end{this->cend()};
    //auto it_end2 = ++this->cbegin();
    for (; it != it_end; ++it){
        //std::cout << (*it).first << std::endl;
        //return;
        //std::cout << "STOCAZZO" << std::endl;
        std::cout << "[" << (*it).first << " : " << (*it).second << "]," ;
        }
    //std::cout << "[" <<  (*it_end).first << " : " << (*it_end).second << "]." << std::endl;
    
  }
 }

/*
template < typename key_type, typename value_type>
Node* BST<key_type,value_type>::find_first (Node * root){

Node* first_key = root.get();
  while(first_key -> left.get()){
  first_key = first_key -> left.get();
  };
  std::cout <<"sono qui "<< first_key -> key <<std::endl;
  return first_key;

}
  */  



template < typename key_type, typename value_type>
void BST<key_type,value_type>::balance(){
    std::vector<std::pair<key_type, value_type>> arr {};
    auto it {this->cbegin()};
    auto it_end{this->cend()};
    int dim = 0;
    
    for ( ; it != it_end; ++it){
    std::cout << dim << std::endl;
    arr.push_back(*it);
    dim = dim + 1;
    }
    root.reset();
    BalancedTree(arr, dim);
    
    
    }



int main() {
  BST<int, int> Tree{};
  Tree.insert(8,2);
  Tree.insert(5,2);
  Tree.insert(3,3);
  Tree.insert(7,3);
  Tree.insert(4,2);
  Tree.insert(14,1);
  Tree.insert(6,2);
  Tree.insert(9,2);
  Tree.insert(13,2);
  Tree.insert(15,2);
  Tree.insert(10,2);
  Tree.insert(20,2);
  Tree.insert(6,2);
  Tree.insert(30,2);
  Tree.insert(16,2);
  
  /*
  Tree.insert(15,2);
  Tree.insert(20,2);
  Tree.insert(30,2);
  Tree.insert(10,2);
  Tree.insert(7,2);
  Tree.insert(3,2);
  */
  BST<int, int>::ConstIterator cfirst = Tree.cbegin();
  BST<int, int>::ConstIterator clast = Tree.cend();
  
  //std::cout << "INIZIO A PRINTARE" << std::endl;
  Tree.print();
  Tree.balance();
  Tree.print();
  //BST<int, int>::Iterator first = Tree.begin();
  //BST<int, int>::Iterator last = Tree.end();
  //BST<int, int>::ConstIterator cfirst = Tree.cbegin();
  //BST<int, int>::ConstIterator clast = Tree.cend();
  std::cout << "funziona lo scheletro" << std::endl;
  };






















 
