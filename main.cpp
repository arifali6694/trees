#include "trees.h"
#include <vector>

int main(){
    BST<int> b; //initialize tree

    std::vector<double> vec {0,3,3,50,35,28,41,78,66,84,100};
    std::vector<double>::iterator itVec;
    for (itVec = vec.begin(); itVec != vec.end(); ++itVec){
        b.Insert(*itVec);
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
