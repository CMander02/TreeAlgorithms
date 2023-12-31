#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

#ifndef B_PLUS_TREE_H
#define B_PLUS_TREE_H

template <class T>
class BPlusTree
{
public:
    BPlusTree(int maxKeyCount);
    bool checkKeyExist(T key);
    bool insertValue(T key, int value);
    bool deleteValue(T key);
    int queryValue(T key);
    void printTree();
    vector<int> rangeQueryValue(T key1, T key2);
    int getPageNum();
    int getLeafPageNum();

private:
    class BPlusTreeNode
    {
    public:
        BPlusTreeNode(bool isLeaf, bool isRoot, int maxKeyCount);
        void printNode();
        int _maxKeyCount;
        int _keyCount;
        bool _isLeaf;
        bool _isRoot;
        T *_keys;
        void **_pointers;
        void *_father;
        void *_prev;
        void *_next;
    };

private:
    BPlusTreeNode *_root;
    int _maxKeyCount;
    int _nodeCount;
    int _leafCount;
    // int _nonLeafCount;
    BPlusTreeNode *findLeaf(T key);
    void insertInNode(BPlusTreeNode *node, T key, void *value);
    void splitNode(BPlusTreeNode *node);
    void deleteInNode(BPlusTreeNode *node, T key);
    void redistributeNode(BPlusTreeNode *node);
};

#endif

// Implementations from BPlusTree.cpp
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

#define BPT BPlusTree
#define BPT_NODE BPlusTree<T>::BPlusTreeNode
#define FOR(i, a, b) for (int i = (a); i < (b); i++)

// public functions

template <class T>
BPT<T>::BPT(int maxKeyCount)
{
    _maxKeyCount = maxKeyCount;
    _root = new BPT_NODE(true, true, _maxKeyCount);
    _nodeCount = 1;
    _leafCount = 1;
}

template <class T>
bool BPT<T>::checkKeyExist(T key)
{
    BPT_NODE *leaf = findLeaf(key);

    // if key in leaf->_keys, don't insert
    FOR(i, 0, leaf->_keyCount)
    if (key == leaf->_keys[i])
        return true;

    return false;
}

template <class T>
bool BPT<T>::insertValue(T key, int value)
{
    // find the leaf page that the key may be in.
    BPT_NODE *leaf = findLeaf(key);

    // if key in leaf->_keys, don't insert
    FOR(i, 0, leaf->_keyCount)
    if (key == leaf->_keys[i])
        return false;

    insertInNode(leaf, key, (void *)value);
    return true;
}

template <class T>
bool BPT<T>::deleteValue(T key)
{
    // find the leaf page that the key may be in.
    BPT_NODE *leaf = findLeaf(key);

    // if key in leaf->_keys, delete it
    FOR(i, 0, leaf->_keyCount)
    {
        if (key == leaf->_keys[i])
        {
            deleteInNode(leaf, key);
            return true;
        }
    }

    // DEBUG: if key doesn't exist
    cout << "error: key " << key << " doesn't exist.\n";
    return false;
}

template <class T>
int BPT<T>::queryValue(T key)
{
    // find the leaf page that the key may be in.
    BPT_NODE *leaf = findLeaf(key);

    // if key in leaf->_keys, return it
    FOR(i, 0, leaf->_keyCount)
    if (key == leaf->_keys[i])
        return (int)(long long)(leaf->_pointers[i + 1]);

    // DEBUG: if key doesn't exist
    cout << "    error: key " << key << " doesn't exist.\n";
    return -1;
}

template <class T>
vector<int> BPT<T>::rangeQueryValue(T key1, T key2)
{
    BPT_NODE *node;
    vector<BPT_NODE *> nodeStack{_root};
    vector<int> queryValues;

    while (!nodeStack.empty())
    {
        node = nodeStack.back();
        nodeStack.pop_back();

        if (node == NULL)
        {
            continue;
        }

        if (!node->_isLeaf)
        {
            if (key2 >= node->_keys[node->_keyCount - 1])
            {
                nodeStack.push_back((BPT_NODE *)node->_pointers[node->_keyCount]);
            }
            for (int i = node->_keyCount - 1; i > 0; i--)
            {
                if (key1 <= node->_keys[i] || key2 >= node->_keys[i - 1])
                {
                    nodeStack.push_back((BPT_NODE *)node->_pointers[i]);
                }
            }
            if (key1 <= node->_keys[0])
            {
                nodeStack.push_back((BPT_NODE *)node->_pointers[0]);
            }
        }
        else
        {
            FOR(i, 0, node->_keyCount)
            {
                if (node->_keys[i] >= key1 && node->_keys[i] <= key2)
                {
                    queryValues.push_back((int)(long long)node->_pointers[i + 1]);
                }
            }
        }
    }
    return queryValues;
}

template <class T>
int BPT<T>::getPageNum()
{
    return _nodeCount;
}

template <class T>
int BPT<T>::getLeafPageNum()
{
    return _leafCount;
}

// private functions

template <class T>
typename BPT_NODE *BPT<T>::findLeaf(T key)
{
    BPT_NODE *node = _root;
    while (!node->_isLeaf)
    {
        FOR(i, 0, node->_keyCount + 1)
        {
            if (i == node->_keyCount || key < node->_keys[i])
            {
                node = (BPT_NODE *)node->_pointers[i];
                break;
            }
        }
    }
    return node;
}

template <class T>
void BPT<T>::insertInNode(BPT_NODE *node, T key, void *value)
{
    // cout << "node: " << node << ", key: " << key << ", value: " << value << endl;
    // find position to insert
    int insertIdx = 0;
    while (insertIdx < node->_keyCount && node->_keys[insertIdx] < key)
        insertIdx++;

    // move the key and values after the position right
    for (int i = node->_keyCount; i > insertIdx; i--)
        node->_keys[i] = node->_keys[i - 1];
    for (int i = node->_keyCount + 1; i > insertIdx + 1; i--)
        node->_pointers[i] = node->_pointers[i - 1];

    // insert key and value
    node->_keys[insertIdx] = key;
    node->_pointers[insertIdx + 1] = value;
    node->_keyCount++;

    // check if this node need to split
    if (node->_keyCount == node->_maxKeyCount)
    {
        splitNode(node);
    }
}

template <class T>
void BPT<T>::deleteInNode(BPT_NODE *node, T key)
{
    int deleteIdx = 0;
    while (key != node->_keys[deleteIdx])
        deleteIdx++;
    for (int i = deleteIdx; i < node->_keyCount - 1; i++)
        node->_keys[i] = node->_keys[i + 1];
    for (int i = deleteIdx + 1; i < node->_keyCount; i++)
        node->_pointers[i] = node->_pointers[i + 1];
    node->_keyCount--;

    // if the number of elements in a node < _maxKeyCount/2
    // redistribute the keys and values in siblings
    if (node->_keyCount < (_maxKeyCount + 1) / 2)
    {
        redistributeNode(node);
    }
}

template <class T>
void BPT<T>::splitNode(BPT_NODE *node)
{
    // create a new node, it will be the sibling in the right
    // move rightmost (_maxKeyCount - _maxKeyCount / 2) elements to new node

    BPT_NODE *newNode = new BPT_NODE(false, false, _maxKeyCount);
    _nodeCount++;

    int midIdx = _maxKeyCount / 2;
    T midKey = node->_keys[midIdx];

    newNode->_keyCount = _maxKeyCount - midIdx;
    FOR(i, 0, newNode->_keyCount)
    {
        newNode->_keys[i] = node->_keys[i + midIdx];
        newNode->_pointers[i + 1] = node->_pointers[i + 1 + midIdx];
    }
    // newNode->_pointers[ newNode->_keyCount ] = node->_pointers[ node->_keyCount ];
    node->_keyCount = midIdx;

    if (node->_isLeaf)
    {
        newNode->_isLeaf = true;
        _leafCount++;
    }

    // update child's father
    if (!node->_isLeaf)
    {
        FOR(i, 0, newNode->_keyCount + 1)
        {
            if (newNode->_pointers[i] != NULL)
            {
                ((BPT_NODE *)newNode->_pointers[i])->_father = (void *)newNode;
            }
        }
    }

    if (node->_isRoot)
    {
        // create a new root
        node->_isRoot = false;

        _root = new BPT_NODE(false, false, _maxKeyCount);
        _nodeCount++;

        _root->_isRoot = true;
        _root->_keys[0] = midKey;
        _root->_pointers[0] = node;
        _root->_pointers[1] = newNode;
        _root->_keyCount = 1;

        node->_father = _root;
        newNode->_father = _root;
    }
    else
    {
        insertInNode((BPT_NODE *)node->_father, midKey, (void *)newNode);
        newNode->_father = node->_father;
    }
    // cout << "after split: _root, node, newNode\n";
    // _root->printNode();
    // node->printNode();
    // newNode->printNode();
    // cout << "node == _root->_pointers[0] : " << (node == _root->_pointers[0]) << endl;
    // cout << "newNode == _root->_pointers[1] : " << (newNode == _root->_pointers[1]) << endl;
}

template <class T>
// B+ tree rebalancing
void BPT<T>::redistributeNode(BPT_NODE *node)
{
    // if the number of elements in a node < _maxKeyCount/2
    // redistribute the keys and values in siblings

    // BPT_NODE* node;
    vector<BPT_NODE *> nodes{_root};
    vector<T> keys;
    vector<T> keys2;
    vector<int> values;
    vector<int> values2;
    int i = 0;

    while (i < nodes.size())
    {
        node = nodes[i];
        if (node != NULL)
        {
            if (node->_isLeaf)
            {
                FOR(i, 0, node->_keyCount)
                {
                    if (i < _maxKeyCount / 2)
                    {
                        keys.push_back(node->_keys[i]);
                        values.push_back((int)(long long)node->_pointers[i + 1]);
                    }
                    else
                    {
                        keys2.push_back(node->_keys[i]);
                        values2.push_back((int)(long long)node->_pointers[i + 1]);
                    }
                }
            }
            else
            {
                FOR(i, 0, node->_keyCount + 1)
                {
                    nodes.push_back((BPT_NODE *)node->_pointers[i]);
                }
            }
        }

        i++;
    }

    // DEBUG
    // for (int i = 0; i < keys.size(); i++) {
    //     cout << "key: " << keys[i] << ", value: " << values[i] << endl;
    // }

    for (auto &node : nodes)
    {
        delete node;
    }

    _root = new BPT_NODE(true, true, _maxKeyCount);
    _nodeCount = 1;
    _leafCount = 1;

    for (int i = 0; i < keys.size(); i++)
    {
        insertValue(keys[i], values[i]);
    }
    for (int i = 0; i < keys2.size(); i++)
    {
        insertValue(keys2[i], values2[i]);
    }
}

template <class T>
void BPT<T>::printTree()
{
    int level = 0;
    BPT_NODE *node;
    vector<BPT_NODE *> nodeStack{_root};
    vector<int> levelStack{0};

    while (!nodeStack.empty())
    {
        node = nodeStack.back();
        nodeStack.pop_back();
        level = levelStack.back();
        levelStack.pop_back();

        FOR(i, 0, level)
        {
            cout << "  ";
        }
        node->printNode();

        if (!node->_isLeaf)
        {
            for (int i = node->_keyCount; i >= 0; i--)
            {
                if (node->_pointers[i] != NULL)
                {
                    nodeStack.push_back((BPT_NODE *)node->_pointers[i]);
                    levelStack.push_back(level + 1);
                }
            }
        }
    }
}

template <class T>
BPT_NODE::BPlusTreeNode(bool isLeaf, bool isRoot, int maxKeyCount)
{
    _maxKeyCount = maxKeyCount;
    _keyCount = 0;
    _isLeaf = isLeaf;
    _isRoot = isRoot;
    _keys = new T[_maxKeyCount];
    _pointers = new void *[_maxKeyCount + 1];
    _pointers[0] = NULL;
    _father = NULL;
    _prev = NULL;
    _next = NULL;
}

template <class T>
void BPT_NODE::printNode()
{
    if (_isLeaf)
    {
        FOR(i, 0, _keyCount)
        {
            cout << _keys[i] << ":" << (int)(long long)_pointers[i + 1] << " | ";
        }
        cout << endl;
    }
    else
    {
        FOR(i, 0, _keyCount)
        {
            cout << _pointers[i] << " | ";
            cout << _keys[i] << ":";
        }
        cout << _pointers[_keyCount] << endl;
    }
}

template class BPlusTree<int>;
template class BPlusTree<string>;
