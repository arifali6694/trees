#include <iostream>

template <typename T>
struct Node{//structs pulic by default
    Node(T value) : data(value), left(nullptr), right(nullptr) {}
    T data;
    bool Insert(T);
    bool search(T);
    void Inorder();
    private:
    Node<T>* left;  //private
    Node<T>* right; //private
    // std::unique_ptr<node<T>>
    // ...
};

template <typename T>
class BST{
    public:
    BST(){};
    bool Insert(T);
    bool search(T);
    void Inorder();  //> void Inorder();
    private:
    Node<T>* root = nullptr;
    //Node<T>* Insert(T);
    //Node<T>* Insert(Node<T>*, T);
    //Node<T>* search(Node<T>*, T);
};


template <typename T>
bool BST<T>::Insert(T key){
    if (root == nullptr){
        root = new Node<T>(key);
        return true;
    }
    return root->Insert(key);
}

template <typename T>
bool Node<T>::Insert(T key){
    if (data == key){
        return false;
    }
    if (data < key){
        if (right == nullptr){
            right = new Node<T>(key);
            return true;
        }
        return right->Insert(key);
    }
    if (left == nullptr){
            left = new Node<T>(key);
            return true;
        }
    return left->Insert(key);
}

template <typename T>
void BST<T>::Inorder(){
    if (root == nullptr){
        return;
    }
    root->Inorder();
}

template <typename T>
void Node<T>::Inorder(){
    if (this ==nullptr){
        return;
        }
    left->Inorder();
    std::cout << data << std::endl;
    right->Inorder();
}

template <typename T>
bool BST<T>::search(T key){
    if (root == nullptr){
        //std::cout<< key << " key not found" <<std::endl;
        return false;
    }
    return root->search(key);
}

template <typename T>
bool Node<T>::search(T key){
    if (data == NULL){
        return false;
    }
    if (data == key){
        //std::cout << "Node "<< key<< " at address :" << this << std::endl;
        return true;
    }
    if (data < key){
        return right->search(key);
    }
    return left->search(key);
}

// template <typename T>
// Node<T>* BST<T>::search(Node<T>* node,T key){
//     if (node != nullptr && node->data == key){
//         std::cout << "Node "<< key<< " at address :" << node << std::endl;
//         return node;}
//     if (node == nullptr){
//         std::cout<< "Node "<< key << " not found" <<std::endl;
//         return nullptr;}
//     if (node->data < key){
//         return search(node->right, key);}
//     return search(node->left, key);
// }

// template <typename T>
// Node<T>* BST<T>::Insert(T value){
//     if (!root){root = new Node<T>(value);return root;} // If root is NULL, insert root node
//     if (value > root->data){root->right = Insert(root->right, value);}
//     else{root->left = Insert(root->left, value);}
//     return root;
// }

// template <typename T>
// Node<T>* BST<T>::Insert(Node<T>* node, T value){
//     if (!node){return new Node<T>(value);}
//     if (value > node->data){node->right = Insert(node->right, value);}
//     else{node->left = Insert(node->left, value);}
//     return node;
// }