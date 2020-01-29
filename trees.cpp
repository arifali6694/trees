#include "trees.h"

BST::BST() : data(0), left(nullptr), right(nullptr) {}

BST::BST(int value){
    data = value;
    left = right = nullptr;
}

BST* BST::Insert(BST* root, int value){
    if (!root){
        // Insert the first node, if root is NULL.
        return new BST(value);
    }
    if (value > root->data){
        root->right = Insert(root->right, value);
    }else{
        root->left = Insert(root->left, value);
    }
    return root;
}

// Inorder traversal
void BST ::Inorder(BST* root){
    if (!root){return;}
    Inorder(root->left);
    std::cout << root->data << std::endl;
    Inorder(root->right);
}

BST* BST::search(BST* root, int key){ 
    // Base Cases: root is null or key is present at root 
    if (root != nullptr && root->data == key){
        std::cout << "Node "<< key<< " at address :" << root << std::endl;
        return root;}
    if (root == nullptr){
        std::cout<< key << " key not found" <<std::endl;
        return nullptr;}
    if (root->data < key)
       return search(root->right, key);
    return search(root->left, key);
}