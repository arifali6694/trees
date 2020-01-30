#include <iostream>

template <typename T>
struct Node{
    Node(T value) : data(value), left(nullptr), right(nullptr) {}
    T data;
    Node<T>* left;
    Node<T>* right;
    private:
    // std::unique_ptr<node<T>>
    // ...
};

template <typename T>
struct BST{
    BST(){};
    Node<T>* Insert(T);
    Node<T>* Insert(Node<T>*, T);
    void Inorder(Node<T>*);
    Node<T>* search(T);
    Node<T>* search(Node<T>*, T);
    Node<T>* root= nullptr; //root node
    private:
};

template <typename T>
Node<T>* BST<T>::Insert(T value){
    if (!root){root = new Node<T>(value);return root;} // If root is NULL, insert root node
    if (value > root->data){root->right = Insert(root->right, value);}
    else{root->left = Insert(root->left, value);}
    return root;
}

template <typename T>
Node<T>* BST<T>::Insert(Node<T>* node, T value){
    if (!node){return new Node<T>(value);}
    if (value > node->data){node->right = Insert(node->right, value);}
    else{node->left = Insert(node->left, value);}
    return node;
}

template <typename T>
void BST<T>::Inorder(Node<T>* node){
    if (!node){return;}
    Inorder(node->left);
    std::cout << node->data << std::endl;
    Inorder(node->right);
}

template <typename T>
Node<T>* BST<T>::search(T key){
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

template <typename T>
Node<T>* BST<T>::search(Node<T>* node,T key){
    if (node != nullptr && node->data == key){
        std::cout << "Node "<< key<< " at address :" << node << std::endl;
        return node;}
    if (node == nullptr){
        std::cout<< "Node "<< key << " not found" <<std::endl;
        return nullptr;}
    if (node->data < key){
        return search(node->right, key);}
    return search(node->left, key);
}