#include <iostream>
#include "TreeStruct/RNG.h" // 包含您的 RNG 类定义
#include "TreeStruct/AVL.h"
#include "TreeStruct/BPT.h"
#include "TreeStruct/RBT.h"
#include <fstream>
#include <string>
#include <algorithm>
#include <chrono>
int main()
{
    chrono::time_point<chrono::steady_clock> start, stop;
    chrono::duration<double> difference_in_time;
    double difference_in_seconds; // Holds the final run time
    // get a start time. insert this line where you want the time measurement begins.
    start = std::chrono::steady_clock::now();
    // get a stop time. insert this line where you want the time measurement begins.
    stop = std::chrono::steady_clock::now();
    // get the difference
    difference_in_time = stop - start;
    // change to seconds
    difference_in_seconds = double(difference_in_time.count());
    cout << "Time taken by program is : " << difference_in_seconds << " seconds" << endl;
    /*%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%*/
    RNG rng; // initialize RNG

    // generate a group of random integers
    std::vector<int> randomInts = rng.generate(10, 1, 100, true); // n=10, rng = [1,100], isSort=True
    std::cout << "Random Integers: ";
    for (int num : randomInts)
    {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    // generate a group of long int numbers
    std::vector<long> randomLongs = rng.generate(1000000000, 1L, 100L, false); // n=1000000000, rng=[long(1),long(100)], isSort=False
    std::cout << "Random Longs: ";
    for (long num : randomLongs)
    {
        std::cout << num << " ";
    }
    std::cout << std::endl;
    /*%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%*/
    AVLTree<int> tree;

    // insert
    tree.insert(10);
    tree.insert(20);
    tree.insert(30);
    tree.insert(40);
    tree.insert(50);
    tree.insert(25);

    // print
    cout << "Inorder traversal of the constructed AVL tree is \n";
    tree.inOrder();
    cout << endl;
    /*%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%*/
    // initialize a B+ tree with order 3
    BPlusTree<int> myTree(10);

    // insert some values
    myTree.insertValue(1, 100);
    myTree.insertValue(2, 200);
    myTree.insertValue(3, 300);

    // search the value for key 2
    std::cout << "Value for key 2: " << myTree.queryValue(2) << std::endl;

    // print the whole tree
    myTree.printTree();

    /*%%%%%%%%%%%%%%%%%%%%%%%%%%%*/
    // initialize a red-black tree
    RBTree<int> tree2;

    // insert
    tree2.insert(10);
    tree2.insert(20);
    tree2.insert(15);
    tree2.insert(25);
    tree2.insert(30);

    // print
    std::cout << "The red-black tree is: " << std::endl;
    tree2.print();

    // search
    if (tree2.search(20) != NULL)
        std::cout << "Key 20 found in the tree." << std::endl;
    else
        std::cout << "Key 20 not found in the tree." << std::endl;

    // delete
    std::cout << "Deleting key 20." << std::endl;
    tree2.remove(20);

    // print again
    std::cout << "The red-black tree after deleting key 20 is: " << std::endl;
    tree2.print();
    return 0;
}
