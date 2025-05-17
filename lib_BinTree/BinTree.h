// Copyright 2024 Kirill Remizov

#ifndef LIB_BINTREE_LIB_BINTREE_HEDER_H_
#define LIB_BINTREE_LIB_BINTREE_HEDER_H_

#include <iostream>
#include <iomanip>
#include <stdexcept>
template <typename T>
class TrNode {
private:
    T val;
    TrNode* left;
    TrNode* right;

public:
    TrNode() : val(T()), left(nullptr), right(nullptr) {}

    TrNode(T value) : val(value), left(nullptr), right(nullptr) {}

    TrNode(const TrNode& other) : val(other.val), left(nullptr), right(nullptr) {
        if (other.left) {
            left = new TrNode(*other.left);
        }
        if (other.right) {
            right = new TrNode(*other.right);
        }
    }

    ~TrNode() {
        delete left;
        delete right;
    }

    T getValue() const { return val; }
    void setValue(T value) { val = value; }

    TrNode* getLeft() const { return left; }
    void setLeft(TrNode* node) { left = node; }

    TrNode* getRight() const { return right; }
    void setRight(TrNode* node) { right = node; }
};

template <typename T>
class BinTree {
private:
    TrNode<T>* root;

    void PrintTree(TrNode<T>* node, int indent = 0) const;
    TrNode<T>* InsertRecursive(TrNode<T>* node, T value);
    TrNode<T>* SearchRecursive(TrNode<T>* node, T value) const;
    TrNode<T>* RemoveRecursive(TrNode<T>* node, T value);
    TrNode<T>* FindMin(TrNode<T>* node) const;

public:
    BinTree() : root(nullptr) {}

    BinTree(const BinTree& other) {
        if (other.root) {
            root = new TrNode<T>(*other.root);
        } else {
            root = nullptr;
        }
    }

    ~BinTree() {
        delete root;
    }

    void Insert(T value) {
        root = InsertRecursive(root, value);
    }

    TrNode<T>* Search(T value) const {
        return SearchRecursive(root, value);
    }

    void Remove(T value) {
        if(root == nullptr) {
            throw std::logic_error("Tree is Empty");
        }
        root = RemoveRecursive(root, value);
    }

    void Print() const {
        PrintTree(root);
    }
};

template <typename T>
void BinTree<T>::PrintTree(TrNode<T>* node, int indent) const {
    if (node == nullptr) return;

    PrintTree(node->getRight(), indent + 4);

    if (indent) {
        std::cout << std::setw(indent) << ' ';
    }
    std::cout << node->getValue() << "\n";

    PrintTree(node->getLeft(), indent + 4);
}

template <typename T>
TrNode<T>* BinTree<T>::InsertRecursive(TrNode<T>* node, T value) {
    if (node == nullptr) {
        return new TrNode<T>(value);
    }

    if (value < node->getValue()) {
        node->setLeft(InsertRecursive(node->getLeft(), value));
    } else if (value > node->getValue()) {
        node->setRight(InsertRecursive(node->getRight(), value));
    }

    return node;
}

template <typename T>
TrNode<T>* BinTree<T>::SearchRecursive(TrNode<T>* node, T value) const {
    if (node == nullptr) {
        return nullptr;
    }

    if (value == node->getValue()) {
        return node;
    } else if (value < node->getValue()) {
        return SearchRecursive(node->getLeft(), value);
    } else {
        return SearchRecursive(node->getRight(), value);
    }
}

template <typename T>
TrNode<T>* BinTree<T>::RemoveRecursive(TrNode<T>* node, T value) {
    if (node == nullptr) {
        throw std::logic_error("Key not found");
    } else if (value < node->getValue()) {
        node->setLeft(RemoveRecursive(node->getLeft(), value));
        return node;
    } else if (value > node->getValue()) {
        node->setRight(RemoveRecursive(node->getRight(), value));
        return node;
    } else if (node->getLeft() == nullptr) {
        TrNode<T>* right_child = node->getRight();
        node->setRight(nullptr);
        delete node;
        return right_child;
    } else if (node->getRight() == nullptr) {
        TrNode<T>* left_child = node->getLeft();
        node->setLeft(nullptr);
        delete node;
        return left_child;
    }
    TrNode<T>* min_node = FindMin(node->getRight());
    node->setValue(min_node->getValue());
    node->setRight(RemoveRecursive(node->getRight(), min_node->getValue()));
    return node;
}

template <typename T>
TrNode<T>* BinTree<T>::FindMin(TrNode<T>* node) const {
    while (node->getLeft() != nullptr) {
        node = node->getLeft();
    }
    return node;
}

#endif // LIB_BINTREE_LIB_BINTREE_HEDER_H_
