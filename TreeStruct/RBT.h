#ifndef _RED_BLACK_TREE_HPP_
#define _RED_BLACK_TREE_HPP_

#include <iomanip>
#include <iostream>
using namespace std;

enum RBTColor
{
    RED,
    BLACK
};

template <class T>
class RBTNode
{
public:
    RBTColor color;  // Color
    T key;           // 关键字(键值)
    RBTNode *left;   // left child
    RBTNode *right;  // right child
    RBTNode *parent; // father

    RBTNode(T value, RBTColor c, RBTNode *p, RBTNode *l, RBTNode *r) : key(value), color(c), parent(), left(l), right(r) {}
};

template <class T>
class RBTree
{
private:
    RBTNode<T> *mRoot; // root

public:
    RBTree();
    ~RBTree();

    // preOrder
    void preOrder();
    // inOrder
    void inOrder();
    // postOrder
    void postOrder();

    // search key (recursive)
    RBTNode<T> *search(T key);
    // search key (iterative)
    RBTNode<T> *iterativeSearch(T key);

    // find minimum
    T minimum();
    // find maximum
    T maximum();

    // find successor
    RBTNode<T> *successor(RBTNode<T> *x);
    // find predecessor
    RBTNode<T> *predecessor(RBTNode<T> *x);

    // insert key
    void insert(T key);

    // delete key
    void remove(T key);

    // destroy red-black tree
    void destroy();

    // print red-black tree
    void print();

private:
    //  preOrder
    void preOrder(RBTNode<T> *tree) const;
    // inOrder
    void inOrder(RBTNode<T> *tree) const;
    // postOrder
    void postOrder(RBTNode<T> *tree) const;

    // search key (recursive)
    RBTNode<T> *search(RBTNode<T> *x, T key) const;
    // search key (iterative)
    RBTNode<T> *iterativeSearch(RBTNode<T> *x, T key) const;

    //  find minimum
    RBTNode<T> *minimum(RBTNode<T> *tree);
    // find maximum
    RBTNode<T> *maximum(RBTNode<T> *tree);

    // left rotate
    void leftRotate(RBTNode<T> *&root, RBTNode<T> *x);
    // right rotate
    void rightRotate(RBTNode<T> *&root, RBTNode<T> *y);
    // insert
    void insert(RBTNode<T> *&root, RBTNode<T> *node);
    // insert fix
    void insertFixUp(RBTNode<T> *&root, RBTNode<T> *node);
    // remove
    void remove(RBTNode<T> *&root, RBTNode<T> *node);
    // remove fix
    void removeFixUp(RBTNode<T> *&root, RBTNode<T> *node, RBTNode<T> *parent);

    // destroy red-black tree
    void destroy(RBTNode<T> *&tree);

    // print red-black tree
    void print(RBTNode<T> *tree, T key, int direction);

#define rb_parent(r) ((r)->parent)
#define rb_color(r) ((r)->color)
#define rb_is_red(r) ((r)->color == RED)
#define rb_is_black(r) ((r)->color == BLACK)
#define rb_set_black(r)     \
    do                      \
    {                       \
        (r)->color = BLACK; \
    } while (0)
#define rb_set_red(r)     \
    do                    \
    {                     \
        (r)->color = RED; \
    } while (0)
#define rb_set_parent(r, p) \
    do                      \
    {                       \
        (r)->parent = (p);  \
    } while (0)
#define rb_set_color(r, c) \
    do                     \
    {                      \
        (r)->color = (c);  \
    } while (0)
};

/*
 * constructor
 */
template <class T>
RBTree<T>::RBTree() : mRoot(NULL)
{
    mRoot = NULL;
}

/*
 * destructor
 */
template <class T>
RBTree<T>::~RBTree()
{
    destroy();
}

/*
 * preOrder
 */

template <class T>
void RBTree<T>::preOrder(RBTNode<T> *tree) const
{
    if (tree != NULL)
    {
        cout << tree->key << " ";
        preOrder(tree->left);
        preOrder(tree->right);
    }
}

template <class T>
void RBTree<T>::preOrder()
{
    preOrder(mRoot);
}

/*
 * inOrder
 */
template <class T>
void RBTree<T>::inOrder(RBTNode<T> *tree) const
{
    if (tree != NULL)
    {
        inOrder(tree->left);
        cout << tree->key << " ";
        inOrder(tree->right);
    }
}

template <class T>
void RBTree<T>::inOrder()
{
    inOrder(mRoot);
}

/*
 * postOrder
 */
template <class T>
void RBTree<T>::postOrder(RBTNode<T> *tree) const
{
    if (tree != NULL)
    {
        postOrder(tree->left);
        postOrder(tree->right);
        cout << tree->key << " ";
    }
}

template <class T>
void RBTree<T>::postOrder()
{
    postOrder(mRoot);
}

/*
 * search key (recursive)
 */
template <class T>
RBTNode<T> *RBTree<T>::search(RBTNode<T> *x, T key) const
{
    if (x == NULL || x->key == key)
        return x;

    if (key < x->key)
        return search(x->left, key);
    else
        return search(x->right, key);
}

template <class T>
RBTNode<T> *RBTree<T>::search(T key)
{
    search(mRoot, key);
}

/*
 * search key (iterative)
 */
template <class T>
RBTNode<T> *RBTree<T>::iterativeSearch(RBTNode<T> *x, T key) const
{
    while ((x != NULL) && (x->key != key))
    {
        if (key < x->key)
            x = x->left;
        else
            x = x->right;
    }

    return x;
}

template <class T>
RBTNode<T> *RBTree<T>::iterativeSearch(T key)
{
    iterativeSearch(mRoot, key);
}

/*
 * find minimum
 */

template <class T>
RBTNode<T> *RBTree<T>::minimum(RBTNode<T> *tree)
{
    if (tree == NULL)
        return NULL;

    while (tree->left != NULL)
        tree = tree->left;
    return tree;
}

template <class T>
T RBTree<T>::minimum()
{
    RBTNode<T> *p = minimum(mRoot);
    if (p != NULL)
        return p->key;

    return (T)NULL;
}

/*
 * find maximum
 */
template <class T>
RBTNode<T> *RBTree<T>::maximum(RBTNode<T> *tree)
{
    if (tree == NULL)
        return NULL;

    while (tree->right != NULL)
        tree = tree->right;
    return tree;
}

template <class T>
T RBTree<T>::maximum()
{
    RBTNode<T> *p = maximum(mRoot);
    if (p != NULL)
        return p->key;

    return (T)NULL;
}

/*
 * find successor
 */
template <class T>
RBTNode<T> *RBTree<T>::successor(RBTNode<T> *x)
{
    // if x has right child, then successor is minimum of right child
    if (x->right != NULL)
        return minimum(x->right);

    // if not, there are 2 cases:
    // (01) x is a "left child", then successor is its parent
    // (02) x is a "right child", then successor is its "lowest parent" with a left child
    RBTNode<T> *y = x->parent;
    while ((y != NULL) && (x == y->right))
    {
        x = y;
        y = y->parent;
    }

    return y;
}

/*
 * find predecessor
 */
template <class T>
RBTNode<T> *RBTree<T>::predecessor(RBTNode<T> *x)
{
    // if x has left child, then predecessor is maximum of left child
    if (x->left != NULL)
        return maximum(x->left);

    // if not, there are 2 cases:
    // (01) x is "a right child", then predecessor is its parent
    // (01) x is "a left child", then predecessor is its "lowest parent" with a right child
    RBTNode<T> *y = x->parent;
    while ((y != NULL) && (x == y->left))
    {
        x = y;
        y = y->parent;
    }

    return y;
}

/*
 * left rotate:
 *      px                              px
 *     /                               /
 *    x                               y
 *   /  \    --(left rotate)-->      / \
 *  lx   y                          x  ry
 *     /   \                       /  \
 *    ly   ry                     lx  ly
 *
 *
 */
template <class T>
void RBTree<T>::leftRotate(RBTNode<T> *&root, RBTNode<T> *x)
{
    // set y as x's right child
    RBTNode<T> *y = x->right;

    // set y's left child as x's right child
    // if y's left child is not NULL, set x as its parent
    x->right = y->left;
    if (y->left != NULL)
        y->left->parent = x;

    // set y's parent as x's parent
    y->parent = x->parent;

    if (x->parent == NULL)
    {
        root = y; // if x's father is NULL, then y is root
    }
    else
    {
        if (x->parent->left == x)
            x->parent->left = y; // if x is left child, then set y as its father's left child
        else
            x->parent->right = y; // if x is right child, then set y as its father's right child
    }

    // set x as y's left child
    y->left = x;
    // set x's father as y
    x->parent = y;
}

/*
 * right rotate:
 *            py                               py
 *           /                                /
 *          y                                x
 *         /  \    --(right rotate)-->      /  \
 *        x   ry                           lx   y
 *       / \                                   / \
 *      lx  rx                                rx  ry
 *
 */
template <class T>
void RBTree<T>::rightRotate(RBTNode<T> *&root, RBTNode<T> *y)
{
    // et x as y's left child
    RBTNode<T> *x = y->left;

    // set x's right child as y's left child
    // if x's right child is not NULL, set y as its parent
    y->left = x->right;
    if (x->right != NULL)
        x->right->parent = y;

    // set y's father as x's father
    x->parent = y->parent;

    if (y->parent == NULL)
    {
        root = x; // if y's father is NULL, then set x as root
    }
    else
    {
        if (y == y->parent->right)
            y->parent->right = x; // if y is right child, then set x as its father's right child
        else
            y->parent->left = x; // if y is left child, then set x as its father's left child
    }

    // set y as x's right child
    x->right = y;

    // set y's father as x
    y->parent = x;
}

/*
 * insert fix
 *
 * use this function after insert node to red-black tree to make it a red-black tree again
 *
 * parameters：
 *     root: root of red-black tree
 *     node: insert node
 */
template <class T>
void RBTree<T>::insertFixUp(RBTNode<T> *&root, RBTNode<T> *node)
{
    RBTNode<T> *parent, *gparent;

    // if parent exists and its color is red
    while ((parent = rb_parent(node)) && rb_is_red(parent))
    {
        gparent = rb_parent(parent);

        // if parent is left child of grandparent
        if (parent == gparent->left)
        {
            // case 1: uncle is red
            {
                RBTNode<T> *uncle = gparent->right;
                if (uncle && rb_is_red(uncle))
                {
                    rb_set_black(uncle);
                    rb_set_black(parent);
                    rb_set_red(gparent);
                    node = gparent;
                    continue;
                }
            }

            // case 2: uncle is black and node is right child
            if (parent->right == node)
            {
                RBTNode<T> *tmp;
                leftRotate(root, parent);
                tmp = parent;
                parent = node;
                node = tmp;
            }

            // case 3: uncle is black and node is left child
            rb_set_black(parent);
            rb_set_red(gparent);
            rightRotate(root, gparent);
        }
        else // if parent is right child of grandparent
        {
            // case 1: uncle is red
            {
                RBTNode<T> *uncle = gparent->left;
                if (uncle && rb_is_red(uncle))
                {
                    rb_set_black(uncle);
                    rb_set_black(parent);
                    rb_set_red(gparent);
                    node = gparent;
                    continue;
                }
            }

            // case 2: uncle is black and node is left child
            if (parent->left == node)
            {
                RBTNode<T> *tmp;
                rightRotate(root, parent);
                tmp = parent;
                parent = node;
                node = tmp;
            }

            // case 3: uncle is black and node is right child
            rb_set_black(parent);
            rb_set_red(gparent);
            leftRotate(root, gparent);
        }
    }

    // set  root color as black
    rb_set_black(root);
}

/*
 * insert node to red-black tree
 *
 * parameters：
 *     root: root of red-black tree
 *     node: insert node
 */
template <class T>
void RBTree<T>::insert(RBTNode<T> *&root, RBTNode<T> *node)
{
    RBTNode<T> *y = NULL;
    RBTNode<T> *x = root;

    // 1. treat red-black tree as a BST, and add node to it
    while (x != NULL)
    {
        y = x;
        if (node->key < x->key)
            x = x->left;
        else
            x = x->right;
    }

    node->parent = y;
    if (y != NULL)
    {
        if (node->key < y->key)
            y->left = node;
        else
            y->right = node;
    }
    else
        root = node;

    // 2. set node color as red
    node->color = RED;

    // 3.  fix it as a red-black tree
    insertFixUp(root, node);
}

/*
 * insert node (with key value) to red-black tree
 *
 * parameters：
 *     tree: root of red-black tree
 *     key: key value of node
 */
template <class T>
void RBTree<T>::insert(T key)
{
    RBTNode<T> *z = NULL;

    // if new node can't be created, return
    if ((z = new RBTNode<T>(key, BLACK, NULL, NULL, NULL)) == NULL)
        return;

    insert(mRoot, z);
}

/*
 * delete fix
 *
 * use this function after delete node to red-black tree to make it a red-black tree again
 *
 * parameters：
 *     root: root of red-black tree
 *     node: node waiting to be fixed
 */
template <class T>
void RBTree<T>::removeFixUp(RBTNode<T> *&root, RBTNode<T> *node, RBTNode<T> *parent)
{
    RBTNode<T> *other;

    while ((!node || rb_is_black(node)) && node != root)
    {
        if (parent->left == node)
        {
            other = parent->right;
            if (rb_is_red(other))
            {
                // Case 1: x's cousin w is red
                rb_set_black(other);
                rb_set_red(parent);
                leftRotate(root, parent);
                other = parent->right;
            }
            if ((!other->left || rb_is_black(other->left)) &&
                (!other->right || rb_is_black(other->right)))
            {
                // Case 2: x's cousin w is black, and w's two children are black
                rb_set_red(other);
                node = parent;
                parent = rb_parent(node);
            }
            else
            {
                if (!other->right || rb_is_black(other->right))
                {
                    // Case 3: x's cousin w is black, w's left child is red, and w's right child is black
                    rb_set_black(other->left);
                    rb_set_red(other);
                    rightRotate(root, other);
                    other = parent->right;
                }
                // Case 4: x's cousin w is black, w's right child is red, and w's left child is any color
                rb_set_color(other, rb_color(parent));
                rb_set_black(parent);
                rb_set_black(other->right);
                leftRotate(root, parent);
                node = root;
                break;
            }
        }
        else
        {
            other = parent->left;
            if (rb_is_red(other))
            {
                // Case 1:  x's cousin w is red
                rb_set_black(other);
                rb_set_red(parent);
                rightRotate(root, parent);
                other = parent->left;
            }
            if ((!other->left || rb_is_black(other->left)) &&
                (!other->right || rb_is_black(other->right)))
            {
                // Case 2: x's cousin w is black, and w's two children are black
                rb_set_red(other);
                node = parent;
                parent = rb_parent(node);
            }
            else
            {
                if (!other->left || rb_is_black(other->left))
                {
                    // Case 3:  x's cousin w is black, w's left child is red, and w's right child is black
                    rb_set_black(other->right);
                    rb_set_red(other);
                    leftRotate(root, other);
                    other = parent->left;
                }
                // Case 4: x's cousin w is black, w's right child is red, and w's left child is any color
                rb_set_color(other, rb_color(parent));
                rb_set_black(parent);
                rb_set_black(other->left);
                rightRotate(root, parent);
                node = root;
                break;
            }
        }
    }
    if (node)
        rb_set_black(node);
}

/*
 * delete (node)，then return the deleted node
 *
 * parameters:
 *     root: root of red-black tree
 *     node: node waiting to be deleted
 */
template <class T>
void RBTree<T>::remove(RBTNode<T> *&root, RBTNode<T> *node)
{
    RBTNode<T> *child, *parent;
    RBTColor color;

    // case when node has both left and right child
    if ((node->left != NULL) && (node->right != NULL))
    {
        // sucessor of the node to be deleted (called "replacement node")
        // replace the node to be deleted, then delete the node
        RBTNode<T> *replace = node;

        // get the successor
        replace = replace->right;
        while (replace->left != NULL)
            replace = replace->left;

        // "node" is not root
        if (rb_parent(node))
        {
            if (rb_parent(node)->left == node)
                rb_parent(node)->left = replace;
            else
                rb_parent(node)->right = replace;
        }
        else
            // "node" is root, renew root
            root = replace;

        // child is the right child of "replacement node", and also the node to be fixed
        // "replacement node" must not have left child, because it is a successor node
        child = replace->right;
        parent = rb_parent(replace);
        // save color of "replacement node"
        color = rb_color(replace);

        // "node" is parent of its successor
        if (parent == node)
        {
            parent = replace;
        }
        else
        {
            // child is not NULL
            if (child)
                rb_set_parent(child, parent);
            parent->left = child;

            replace->right = node->right;
            rb_set_parent(node->right, replace);
        }

        replace->parent = node->parent;
        replace->color = node->color;
        replace->left = node->left;
        node->left->parent = replace;

        if (color == BLACK)
            removeFixUp(root, child, parent);

        delete node;
        return;
    }

    if (node->left != NULL)
        child = node->left;
    else
        child = node->right;

    parent = node->parent;
    // save color of "replacement node"
    color = node->color;

    if (child)
        child->parent = parent;

    // "node" is not root
    if (parent)
    {
        if (parent->left == node)
            parent->left = child;
        else
            parent->right = child;
    }
    else
        root = child;

    if (color == BLACK)
        removeFixUp(root, child, parent);
    delete node;
}

/*
 * delete node (with key value)
 *
 * parameters：
 *     tree: root of red-black tree
 */
template <class T>
void RBTree<T>::remove(T key)
{
    RBTNode<T> *node;

    // search node with key value, if exist, them remive it
    if ((node = search(mRoot, key)) != NULL)
        remove(mRoot, node);
}

/*
 * destroy red-black tree
 */
template <class T>
void RBTree<T>::destroy(RBTNode<T> *&tree)
{
    if (tree == NULL)
        return;

    if (tree->left != NULL)
        return destroy(tree->left);
    if (tree->right != NULL)
        return destroy(tree->right);

    delete tree;
    tree = NULL;
}

template <class T>
void RBTree<T>::destroy()
{
    destroy(mRoot);
}

/*
 * print BST
 *
 * key        --   key value of node
 * direction  --
 *                  0，root node;
 *                  -1, left child;
 *                  1, right child.
 */

template <class T>
void RBTree<T>::print(RBTNode<T> *tree, T key, int direction)
{
    if (tree != NULL)
    {
        if (direction == 0) // tree is root
            cout << setw(2) << tree->key << "(B) is root" << endl;
        else // tree is split nodeS
            cout << setw(2) << tree->key << (rb_is_red(tree) ? "(R)" : "(B)") << " is " << setw(2) << key << "'s " << setw(12) << (direction == 1 ? "right child" : "left child") << endl;

        print(tree->left, tree->key, -1);
        print(tree->right, tree->key, 1);
    }
}

template <class T>
void RBTree<T>::print()
{
    if (mRoot != NULL)
        print(mRoot, mRoot->key, 0);
}

#endif