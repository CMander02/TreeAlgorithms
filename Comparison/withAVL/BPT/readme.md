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