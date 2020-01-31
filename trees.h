#include <iostream>
#include <optional>

// so clean :D
template <typename T>
class BST {
public:
    BST() : m_root(nullptr){};
    // ~BST(); if using raw pointers we need to clean up :)

    // From the users standpoint they just want to
    // insert something in the tree. They DO NOT
    // want to be fussing with pointers
    void insert(T);
    void inorder();
    //    std::optional<T> search(T);

private:
    // who else wants this?!
    // if you are going to balance this tree it will be storing
    // extra information which would be useless to other variations
    // of trees.
    struct Node {
        Node(T value) : data(value), left(nullptr), right(nullptr) {}
        T data;
        Node* left;
        Node* right;
    };

    // private implmentation functions
    Node* insert(Node* node, T val);
    void inorder(Node* node);

    Node* m_root;  // root node
};

template <typename T>
void BST<T>::insert(T value) {
    if (!m_root) {
        m_root = new Node(value);
        return;
    }

    if (value > m_root->data) {
        m_root->right = insert(m_root->right, value);
    } else {
        m_root->left = insert(m_root->left, value);
    }
}

template <typename T>
typename BST<T>::Node* BST<T>::insert(Node* node, T val) {
    if (!node) {
        return new Node(val);
    }
    if (val > node->data) {
        return insert(node->right, val);
    } else {
        return insert(node->left, val);
    }
}

template <typename T>
void BST<T>::inorder() {
    inorder(m_root);
}

template <typename T>
void BST<T>::inorder(Node* node) {
    if (!node) {
        return;
    }
    inorder(node->left);
    std::cout << node->data << std::endl;
    inorder(node->right);
}

