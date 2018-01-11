#include <iostream>
#include <string>
#include <math.h>
#include <memory>

enum class Insertion_method { push_back, push_front };
enum class Prune_method { prune_back, prune_front };

std::pair<key_type,value_type>

class Tree {

    private:
 
        struct node {
        
            key_type key;
            value_type data;
            
            std::unique_ptr<node> right;
            std::unique_ptr<node> left;

            node(key_type node_key, value_type node_value, node* r = nullptr, node* l = nullptr): key{node_key}, data{node_value}, right{r}, left{l} {}
        };
        

        std::unique_ptr<node> top;
        unsigned int _size;
        
    public:
    
        Tree(): top{nullptr}, _size {0} {}

        
};

int main() {

    return 0;

}






















