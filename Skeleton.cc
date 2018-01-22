#include <iostream>
#include <memory>
#include <utility>
#include <vector>
#include <numeric>


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
 
  // copy-constructor for the node
  Node(const Node& other) {
    value = other.value;
    key = other.key;
    parent = other.parent;
    left.reset(other.left.get());
    right.reset(other.right.get());
    std::cout << "Node copy-constructed." << std::endl; }
  
  
  
  
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
  
    
    
    // Copy-Constructor
    BST(const BST &other) { 
    root.reset(new Node(*(other.root)));
    }  
    
    // Move-Constructor
    BST( BST<key_type, value_type>&& other) {
    root = std::move(other.root);
    }
    
    //Copy-Assignment.
    BST& operator=(const BST<key_type, value_type>& other)
    {
      std::cout << "copy-assignment..." << std::endl;

      if (this == &other) {
      return *this; // handle self-assignment
        }
        
      if (root != nullptr)
      {
        std::cout << "Clearing out previous content at left-side..." << std::endl;
        root.reset();
      }

      // if the other tree isn't empty, it's copied from its root.
      if (other.root != nullptr) {
        root.reset(new Node(*(other.root)));
        }

      return *this;
    }
    
    
     // move assignment
    BST& operator=(BST<key_type, value_type>&& other)
    {
      if (root != nullptr){
            root.reset();
         }
      if (other.root != nullptr)
      {
        std::cout << "Moving root to the left-side." << std::endl;
        root = std::move(other.root);
      }

      return *this;
    }
    
      
    
  
    void BalancedTree(std::vector<std::pair<key_type, value_type>> array,int dim){
    std::cout << "SONO IO" << std::endl;
    
    
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
    std::cout<<"Sono finder e sono "<<std::endl;
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
            std::cout<<"i è "<<i<<std::endl;
        };
        while (indicatorjj1 != finder){
            e++;
            j++;
            
            std::cout<<"j è "<<j<<std::endl;
            indicatorjj1[0] = indicator[j];
            indicatorjj1[1] = indicator[j+1];
        };
        
        indicatorjj1[0] = 0;
        indicatorjj1[1] = 0;
        
        mid = (b+e)/2;
        std::cout<<"b è "<<b<<std::endl;
        std::cout<<"e è "<<e<<std::endl;
        std::cout<<"mid è "<<mid<<std::endl;
        indicator[mid] = 0;
        sum_indicator = std::accumulate(indicator.begin(), indicator.end(), 0);
        insert((array[mid]).first,(array[mid]).second);
    };
    std::cout<<"la somma è "<<sum_indicator<<std::endl;
    finder.clear();
    indicator.clear();
    indicatorjj1.clear();
    std::cout<<"la somma è ancora "<<sum_indicator<<std::endl;
    //return root.get();
    }
 
  
   

  
 
  
  
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
    std::cout << "DO FASTIDIO?" << std::endl;
    //root.reset(temp);
    
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
  Tree.balance();
  Tree.print();
  /*
  //std::cout << "INIZIO A PRINTARE" << std::endl;
  Tree.print();
  BST<int, int> Other_Tree(Tree);
  //BST<int, int> Moved_Tree(std::move(Tree));
  //Tree.clear();
  //Other_Tree.print();
  
  BST<int, int> Tree_to_be_assigned{};
  Tree_to_be_assigned.insert(5,7),
  Tree_to_be_assigned.insert(13,2);
  Tree_to_be_assigned.insert(15,2);
  Tree_to_be_assigned.insert(10,2);
  Tree_to_be_assigned.insert(20,2);
  
  BST<int, int> Tree_short{};
  Tree_short.insert(5,7),
  Tree_short.insert(13,2);
  Tree_short.insert(15,2);
  Tree_short.insert(10,2);
  Tree_short.insert(20,2);
  
  Tree.insert(15,2);
  Tree.insert(20,2);
  Tree.insert(30,2);
  Tree.insert(10,2);
  Tree.insert(7,2);
  Tree.insert(3,2);
  
  //BST<int, int>::ConstIterator cfirst = Tree.cbegin();
  //BST<int, int>::ConstIterator clast = Tree.cend();
  
  //std::cout << "INIZIO A PRINTARE" << std::endl;
  //Tree.print();
  //Other_Tree.print();
  Other_Tree.insert(40,40);
  Other_Tree.print();
  Tree.print();
  std::cout << "Print moved Tree" << std::endl;
  //Moved_Tree.print();
  std::cout << "Print Tree_to_be assigned before the assignment" << std::endl;
  Tree_to_be_assigned.print();
  //Tree_to_be_assigned = Moved_Tree;
  Tree_to_be_assigned.insert(1,1);
  Tree_to_be_assigned.print();
  //Moved_Tree.print();
  
  std::cout << "Study moving assignment" << std::endl;
  //Tree_to_be_assigned = Moved_Tree; //Cannot assign Tree since is moved.
  //Tree_to_be_assigned.print();
  Other_Tree = std::move(Tree_short);
  Other_Tree.insert(40,40);
  Other_Tree.print(); //expected "shorter" tree
  Tree_short.print(); //expected empty tree
  //BST<int, int>::Iterator first = Tree.begin();
  //BST<int, int>::Iterator last = Tree.end();
  //BST<int, int>::ConstIterator cfirst = Tree.cbegin();
  //BST<int, int>::ConstIterator clast = Tree.cend();
  std::cout << "funziona lo scheletro" << std::endl;*/
  };






















 
