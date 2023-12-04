#ifndef _AVL_TREE_HPP_
#define _AVL_TREE_HPP_

#include <iostream>
#include <iomanip>
using namespace std;

template <class T>
class AVLNode
{
public:
    T key;           // Key value
    int height;      // Height of the node
    AVLNode *left;   // Left child
    AVLNode *right;  // Right child
    AVLNode *parent; // Parent node

    // Constructor
    AVLNode(T value, AVLNode *p = nullptr, AVLNode *l = nullptr, AVLNode *r = nullptr)
        : key(value), height(1), parent(p), left(l), right(r) {} // Height is 1 for leaf nodes
};

template <class T>
class AVLTree
{
private:
    AVLNode<T> *mRoot; // Root of the AVL tree

public:
    AVLTree();
    ~AVLTree();

    // Traversal functions
    void preOrder();
    void inOrder();
    void postOrder();

    // Search functions
    AVLNode<T> *search(T key);
    AVLNode<T> *iterativeSearch(T key);

    // Minimum and maximum
    T minimum();
    T maximum();

    // Successor and predecessor
    AVLNode<T> *successor(AVLNode<T> *x);
    AVLNode<T> *predecessor(AVLNode<T> *x);

    // Insert and remove
    void insert(T key);
    void remove(T key);

    // Destroy the tree
    void destroy();

    // Print the tree
    void print();

private:
    // Traversal helpers
    void preOrder(AVLNode<T> *tree) const;
    void inOrder(AVLNode<T> *tree) const;
    void postOrder(AVLNode<T> *tree) const;

    // Search helpers
    AVLNode<T> *search(AVLNode<T> *x, T key) const;
    AVLNode<T> *iterativeSearch(AVLNode<T> *x, T key) const;

    // Find minimum and maximum node
    AVLNode<T> *minimum(AVLNode<T> *tree);
    AVLNode<T> *maximum(AVLNode<T> *tree);

    // Insertion and removal helpers
    // AVLNode<T> *insert(AVLNode<T> *&root, AVLNode<T> *node);
    void insert(AVLNode<T> *&node, T key);
    // AVLNode<T> *remove(AVLNode<T> *&root, AVLNode<T> *node);
    void remove(AVLNode<T> *&root, AVLNode<T> *node);

    // Balancing and rotation functions
    void leftRotate(AVLNode<T> *&root, AVLNode<T> *x);
    void rightRotate(AVLNode<T> *&root, AVLNode<T> *y);

    int getBalanceFactor(AVLNode<T> *node);
    void rebalance(AVLNode<T> *&root, AVLNode<T> *node);

    // Utility functions
    void updateHeight(AVLNode<T> *node);
    int height(AVLNode<T> *node) const;
    void destroy(AVLNode<T> *&tree);
    void print(AVLNode<T> *tree, T key, int direction) const;
};

// AVLTree constructor
template <class T>
AVLTree<T>::AVLTree() : mRoot(nullptr) {}

// AVLTree destructor
template <class T>
AVLTree<T>::~AVLTree()
{
    destroy(mRoot);
}

// Recursive destruction of the tree
template <class T>
void AVLTree<T>::destroy(AVLNode<T> *&node)
{
    if (node != nullptr)
    {
        destroy(node->left);
        destroy(node->right);
        delete node;
        node = nullptr;
    }
}

// insert (public)
template <class T>
void AVLTree<T>::insert(T key)
{
    if (mRoot == nullptr)
    {
        mRoot = new AVLNode<T>(key, nullptr, nullptr, nullptr);
    }
    else
    {
        AVLNode<T> *start = &*mRoot;
        insert(start, key);
        rebalance(mRoot, start);
    }
}

// insert (private)
template <class T>
void AVLTree<T>::insert(AVLNode<T> *&node, T key)
{
    AVLNode<T> *parent = node;
    bool leftChild;
    while (node != nullptr)
    {
        parent = node;
        if (key < node->key)
        {
            node = node->left;
            leftChild = true;
        }
        else
        {
            node = node->right;
            leftChild = false;
        }
    }

    if (leftChild)
        parent->left = new AVLNode<T>(key, parent, nullptr, nullptr);
    else
        parent->right = new AVLNode<T>(key, parent, nullptr, nullptr);

    node = parent;
}

// delete (public)
template <class T>
void AVLTree<T>::remove(T key)
{
    if (mRoot == nullptr)
        return;

    remove(mRoot, iterativeSearch(key));
}

// delete (private)
template <class T>
void AVLTree<T>::remove(AVLNode<T> *&root, AVLNode<T> *node)
{
    AVLNode<T> *start;
    if (node->left == nullptr && node->right == nullptr)
    {
        if (root == node)
        {
            mRoot = nullptr;
            delete node;
            return;
        }

        if (node->key < node->parent->key)
            node->parent->left = nullptr;
        else
            node->parent->right = nullptr;
        start = node->parent;
        delete node;
    }
    else if (node->left == nullptr || node->right == nullptr)
    {
        if (root == node)
        {
            if (node->left)
                mRoot = node->left;
            else
                mRoot = node->right;

            rebalance(mRoot, mRoot);
            delete node;
            return;
        }

        if (node->left && node->key < node->parent->key)
        {
            node->parent->left = node->left;
            start = node->left;
            delete node;
        }
        else if (node->left && node->key >= node->parent->key)
        {
            node->parent->right = node->left;
            start = node->left;
            delete node;
        }
        else if (node->right && node->key < node->parent->key)
        {
            node->parent->left = node->right;
            start = node->right;
            delete node;
        }
        else if (node->right && node->key >= node->parent->key)
        {
            node->parent->right = node->right;
            start = node->right;
            delete node;
        }
    }
    else
    {
        start = successor(node);
        if (root == node)
        {
            mRoot->key = start->key;
            if (start->key < start->parent->key)
                start->parent->left = nullptr;
            else
                start->parent->right = nullptr;
            rebalance(mRoot, mRoot);
            delete start;
            return;
        }
        else if (node->key < node->parent->key)
            node->parent->left = start;
        else
            node->parent->right = start;
        delete node;
    }

    rebalance(mRoot, start);
}

// Pre-order traversal (public)
template <class T>
void AVLTree<T>::preOrder()
{
    preOrder(mRoot);
}

// Pre-order traversal (private)
template <class T>
void AVLTree<T>::preOrder(AVLNode<T> *node) const
{
    if (node != nullptr)
    {
        cout << node->key << " ";
        preOrder(node->left);
        preOrder(node->right);
    }
}

// In-order traversal (public)
template <class T>
void AVLTree<T>::inOrder()
{
    inOrder(mRoot);
}

// In-order traversal (private)
template <class T>
void AVLTree<T>::inOrder(AVLNode<T> *node) const
{
    if (node != nullptr)
    {
        inOrder(node->left);
        cout << node->key << " ";
        inOrder(node->right);
    }
}

// Post-order traversal (public)
template <class T>
void AVLTree<T>::postOrder()
{
    postOrder(mRoot);
}

// Post-order traversal (private)
template <class T>
void AVLTree<T>::postOrder(AVLNode<T> *node) const
{
    if (node != nullptr)
    {
        postOrder(node->left);
        postOrder(node->right);
        cout << node->key << " ";
    }
}

// Search key (public)
template <class T>
AVLNode<T> *AVLTree<T>::search(T key)
{
    return search(mRoot, key);
}

// Recursive search (private)
template <class T>
AVLNode<T> *AVLTree<T>::search(AVLNode<T> *node, T key) const
{
    if (node == nullptr || key == node->key)
    {
        return node;
    }

    if (key < node->key)
    {
        return search(node->left, key);
    }
    else
    {
        return search(node->right, key);
    }
}

// Iterative search (public)
template <class T>
AVLNode<T> *AVLTree<T>::iterativeSearch(T key)
{
    return iterativeSearch(mRoot, key);
}

// Iterative search (private)
template <class T>
AVLNode<T> *AVLTree<T>::iterativeSearch(AVLNode<T> *node, T key) const
{
    while (node != nullptr && key != node->key)
    {
        if (key < node->key)
        {
            node = node->left;
        }
        else
        {
            node = node->right;
        }
    }
    return node;
}

// Find the minimum key value (public)
template <class T>
T AVLTree<T>::minimum()
{
    AVLNode<T> *node = minimum(mRoot);
    if (node != nullptr)
    {
        return node->key;
    }
    return T(); // Return default value if tree is empty
}

// Find the minimum node (private)
template <class T>
AVLNode<T> *AVLTree<T>::minimum(AVLNode<T> *node)
{
    if (node == nullptr)
    {
        return nullptr;
    }

    while (node->left != nullptr)
    {
        node = node->left;
    }
    return node;
}

// Find the maximum key value (public)
template <class T>
T AVLTree<T>::maximum()
{
    AVLNode<T> *node = maximum(mRoot);
    if (node != nullptr)
    {
        return node->key;
    }
    return T(); // Return default value if tree is empty
}

// Find the maximum node (private)
template <class T>
AVLNode<T> *AVLTree<T>::maximum(AVLNode<T> *node)
{
    if (node == nullptr)
    {
        return nullptr;
    }

    while (node->right != nullptr)
    {
        node = node->right;
    }
    return node;
}

// Find the successor of a given node
template <class T>
AVLNode<T> *AVLTree<T>::successor(AVLNode<T> *x)
{
    if (x == nullptr)
    {
        return nullptr;
    }

    // If the right subtree of node x is nonempty, then the successor of x is just the leftmost node of the right subtree
    if (x->right != nullptr)
    {
        return minimum(x->right);
    }

    // Otherwise, the successor of x is the lowest ancestor of x whose left child is also an ancestor of x.
    AVLNode<T> *y = x->parent;
    while (y != nullptr && x == y->right)
    {
        x = y;
        y = y->parent;
    }
    return y;
}

// Find the predecessor of a given node
template <class T>
AVLNode<T> *AVLTree<T>::predecessor(AVLNode<T> *x)
{
    if (x == nullptr)
    {
        return nullptr;
    }

    // If the left subtree of node x is nonempty, then the predecessor of x is just the rightmost node of the left subtree
    if (x->left != nullptr)
    {
        return maximum(x->left);
    }

    // Otherwise, the predecessor of x is the lowest ancestor of x whose right child is also an ancestor of x.
    AVLNode<T> *y = x->parent;
    while (y != nullptr && x == y->left)
    {
        x = y;
        y = y->parent;
    }
    return y;
}
/*
    Rotations
*/

// Left Rotate
template <class T>
void AVLTree<T>::leftRotate(AVLNode<T> *&root, AVLNode<T> *x)
{
    AVLNode<T> *y = x->right;
    x->right = y->left;

    if (y->left != nullptr)
    {
        y->left->parent = x;
    }

    y->parent = x->parent;

    if (x->parent == nullptr)
    {
        root = y;
    }
    else if (x == x->parent->left)
    {
        x->parent->left = y;
    }
    else
    {
        x->parent->right = y;
    }

    y->left = x;
    x->parent = y;

    // Update heights
    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;
}

// Right Rotate
template <class T>
void AVLTree<T>::rightRotate(AVLNode<T> *&root, AVLNode<T> *y)
{
    AVLNode<T> *x = y->left;
    y->left = x->right;

    if (x->right != nullptr)
    {
        x->right->parent = y;
    }

    x->parent = y->parent;

    if (y->parent == nullptr)
    {
        root = x;
    }
    else if (y == y->parent->right)
    {
        y->parent->right = x;
    }
    else
    {
        y->parent->left = x;
    }

    x->right = y;
    y->parent = x;

    // Update heights
    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;
}

// Get Balance Factor of a node
template <class T>
int AVLTree<T>::getBalanceFactor(AVLNode<T> *node)
{
    if (node == nullptr)
    {
        return 0;
    }
    return height(node->left) - height(node->right);
}

// Rebalance the tree
template <class T>
void AVLTree<T>::rebalance(AVLNode<T> *&root, AVLNode<T> *node)
{
    // Update the height of the node
    updateHeight(node);

    int balanceFactor = getBalanceFactor(node);

    // Left heavy situation
    if (balanceFactor > 1)
    {
        // Left-Left case
        if (getBalanceFactor(node->left) >= 0)
        {
            rightRotate(root, node);
        }
        // Left-Right case
        else
        {
            leftRotate(root, node->left);
            rightRotate(root, node);
        }
    }
    // Right heavy situation
    else if (balanceFactor < -1)
    {
        // Right-Right case
        if (getBalanceFactor(node->right) <= 0)
        {
            leftRotate(root, node);
        }
        // Right-Left case
        else
        {
            rightRotate(root, node->right);
            leftRotate(root, node);
        }
    }
}

// Update the height of a node
template <class T>
void AVLTree<T>::updateHeight(AVLNode<T> *node)
{
    if (node != nullptr)
    {
        node->height = 1 + max(height(node->left), height(node->right));
    }
}

// Utility function to get the height of a node
template <class T>
int AVLTree<T>::height(AVLNode<T> *node) const
{
    return node == nullptr ? 0 : node->height;
}

// Print the tree
template <class T>
void AVLTree<T>::print()
{
    if (mRoot != nullptr)
    {
        print(mRoot, mRoot->key, 0);
    }
}

// Print the tree (private helper)
template <class T>
void AVLTree<T>::print(AVLNode<T> *node, T key, int direction) const
{
    if (node != nullptr)
    {
        if (direction == 0)
        { // Tree is root
            cout << setw(2) << node->key << " is root" << endl;
        }
        else
        { // Tree is subtree
            cout << setw(2) << node->key << " is " << setw(2) << key << "'s " << (direction == 1 ? "right child" : "left child") << ", balance factor is " << getBalanceFactor(node) << endl;
        }

        print(node->left, node->key, -1);
        print(node->right, node->key, 1);
    }
}

#endif // _AVL_TREE_HPP_
