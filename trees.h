#include <iostream>

template<typename T>
struct Node {
    private:
    T data;
    Node<T>* left, right;
    // std::unique_ptr<node<T>>
    // ...
};

template<typename T>
struct BST
{   private:
    // data;
   // BST<T>* left;
   // BST<T>* right;
    Node<T> *root= nullptr;
    public:
    BST() : {}

    BST(T Value){
        data = Value;
        left = right = nullptr;
    }

BST<T>* Insert(BST<T>* root, T value){
    if (!root){
        // Insert the first node, if root is NULL.
        return new BST<T>(value);
    }
    if (value > root->data){
        root->right = Insert(root->right, value);
    }else{
        root->left = Insert(root->left, value);
    }
    return root;
}

void Insert(Node<T> value){
    if root 
}

void Inorder(BST<T>* root){
    if (!root){return;}
    Inorder(root->left);
    std::cout << root->data << std::endl;
    Inorder(root->right);
}

BST<T>* search(BST<T>* root, T key){
    // Base Cases: root is null or key is present at root
    if (root != nullptr && root->data == key){
        std::cout << "Node "<< key<< " at address :" << root << std::endl;
        return root;}
    if (root == nullptr){
        std::cout<< key << " key not found" <<std::endl;
        return nullptr;}
    if (root->data < key){
        return search(root->right, key);}
    return search(root->left, key);
}
};

