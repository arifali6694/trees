#include <iostream>
#include <optional>
#include <memory>

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
        std::unique_ptr<Node> left;
        std::unique_ptr<Node> right;
    };

    // private implmentation functions
    void insert(std::unique_ptr<Node>& node, T val);
    void inorder(std::unique_ptr<Node>& node);

    std::unique_ptr<Node> m_root;  // root node
};

template <typename T>
void BST<T>::insert(T value) {
    if (!m_root) {
        m_root = std::make_unique<Node>(value);
        return;
    }

    if (value > m_root->data) {
        insert(m_root->right, value);
    } else {
        insert(m_root->left, value);
    }
}

template <typename T>
void BST<T>::insert(std::unique_ptr<Node>& node, T val) {
    if (!node) {
        node = std::make_unique<Node>(val);
        return;
    }
    if (val > node->data) {
        insert(node->right, val);
    } else {
        insert(node->left, val);
    }
}

template <typename T>
void BST<T>::inorder() {
    inorder(m_root);
}

template <typename T>
void BST<T>::inorder(std::unique_ptr<Node>& node) {
    if (!node) {
        return;
    }
    inorder(node->left);
    std::cout << node->data << std::endl;
    inorder(node->right);
}

