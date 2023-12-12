#include <string>
#include <vector>
#include "BPlusTree.h"

#define FOR(i,a,b) for(int i=(a);i<(b);i++)

using namespace std;

// COMPILING: g++ --std=c++11 test_bpt.cpp BPlusTree.cpp -o main
// RUNNING: ./main

// BPlusTree(int maxKeyCount);                             #Define TREE, max Key in one Node
//                                                         move rightmost (_maxKeyCount - _maxKeyCount / 2) elements to new node on insertion
// bool checkKeyExist(T key);                              #Return bool, check if key has vaue
// bool insertValue(T key, int value);                     #Return bool, insert key with value, ignored if key already has value
// bool deleteValue(T key);                                #Return bool, deletes input key
// int queryValue(T key);                                  #Return input key value
// void printTree();                                       #Return bool, print<Tree>
// vector<int> rangeQueryValue(T key1, T key2);            #Return <vector> values of key1 to key2
// int getPageNum();                                       #Return Node number
// int getLeafPageNum();                                   #Return Leaf number

int main() {
    auto bpt = BPlusTree<int>(62);
    // In Leaf, its <int> : <int>
    vector<int> toInsert {34,567,23,56,645,3,452,245,563,56,542,2987,23489,35489,328};

    for (auto& i : toInsert) {
        bpt.insertValue(i, i);
    }
    bpt.printTree();
    cout << "Node: " << bpt.getPageNum() << endl;
    bpt.insertValue(8, 7);
    bpt.insertValue(7, 63);
    bpt.deleteValue(7);
    bpt.deleteValue(35489);
    bpt.deleteValue(23489);

    bpt.printTree();
    cout << "Node " << bpt.getPageNum() << endl;

    // New tree key stores string instead of int
    auto bpt2 = BPlusTree<string>(8);
    // In Leaf, its <string> : <string>
    
    FOR(i, 0, 100) {
        bpt2.insertValue(to_string(2*i), i);
    }
    
    cout << "BPT2 Insertion " << endl;
    bpt2.printTree();
    
    cout << "BPT2 Deletion " << endl;
    FOR(i, 0, 100) {
        bpt2.deleteValue(to_string(2*i));
    }
    bpt2.printTree();
    
    cout << "BPT2 Insertion 2 " << endl;
    FOR(i, 0, 10) {
        bpt2.insertValue(to_string(2*i), i);
    }
    
    bpt2.printTree();
    
    cout << "Node: " << bpt2.getPageNum() << endl;
    cout << "Leaf: " << bpt2.getLeafPageNum() << endl;

    for (auto& i : bpt.rangeQueryValue(-1, 100)) {
        cout << i << ' ';
    }
    cout << endl;

    cout << "query 7" << bpt2.queryValue("14") << endl;
    cout << "query 4:" << bpt2.queryValue("4") << endl;
    cout << "query 7" << bpt.queryValue(56) << endl;
    cout << "query 4:" << bpt.queryValue(245) << endl;


    bpt.deleteValue(10);
    bpt.deleteValue(1);
    bpt.deleteValue(2);
    bpt.deleteValue(4);
    bpt.deleteValue(12);
    bpt.deleteValue(9487);

    bpt.printTree();

    return 0;
}
