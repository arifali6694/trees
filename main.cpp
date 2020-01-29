#include "trees.h"
#include <vector>

int main(){
    BST<int> b;
    std::vector<double> vec {0,3,50,35,28,41,78,66,84,100};
    //std::vector<double>::iterator ;

    for (auto& k : vec){
        if (root == nullptr){
            root = b.Insert(root, k);
        }else {
            b.Insert(root, k);
        }
    }
    /*
    "auto" = vector<double>::iterator
    for(auto it = vec.begin(); it < vec.end; ++it) {
        // blah
    }
    */
    b.Inorder(root);
    b.search(root,3);
    return 0;
}
// TODO: 
//adding a struct 'node' instead of using the tree object each time. e.g Insert (int v) NOT Insert(BST*, int v)
//using unique ptrs.
//using maps for keys.
//public class tree iterator

