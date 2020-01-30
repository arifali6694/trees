#include "trees.h"
#include <vector>

int main(){
    BST<int> b; //initialize tree root 
    std::vector<double> vec {0,3,50,35,28,41,78,66,84,100};
    //std::vector<double>::iterator ;

    for (auto& k : vec){b.Insert(k);}

    /*
    "auto" = vector<double>::iterator
    for(auto it = vec.begin(); it < vec.end; ++it) {
        //
    }
    */
    b.Inorder(b.root);
    b.search(3);
    b.search(4);
    return 0;
}
// TODO: 
//using unique ptrs.
//using maps for keys.
//public class tree iterator
