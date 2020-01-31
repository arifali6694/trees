#include "trees.h"
#include <vector>

int main(){
    BST<int> b; //initialize tree
    std::vector<double> vec {0,3,3,50,35,28,41,78,66,84,100};
    std::vector<double>::iterator it;
    for (it = vec.begin(); it != vec.end(); ++it){
        b.insert(*it);
    }
    b.inorder();
    return 0;
}
