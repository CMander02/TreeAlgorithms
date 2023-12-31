#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

#ifndef B_PLUS_TREE_H
#define B_PLUS_TREE_H

template <class T>
class BPlusTree {
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
        class BPlusTreeNode {
            public:
                BPlusTreeNode(bool isLeaf, bool isRoot, int maxKeyCount);
                void printNode();
                int _maxKeyCount;
                int _keyCount;
                bool _isLeaf;
                bool _isRoot;
                T* _keys;
                void** _pointers;
                void* _father;
                void* _prev;
                void* _next;
        };
    private:
        BPlusTreeNode* _root;
        int _maxKeyCount;
        int _nodeCount;
        int _leafCount;
        // int _nonLeafCount;
        BPlusTreeNode* findLeaf(T key);
        void insertInNode(BPlusTreeNode* node, T key, void* value);
        void splitNode(BPlusTreeNode* node);
        void deleteInNode(BPlusTreeNode* node, T key);
        void redistributeNode(BPlusTreeNode* node);
};

#endif
