#include <iostream>
#include "TreeStruct/RNG.h" 
#include "TreeStruct/AVL.h"
#include "TreeStruct/RBT.h"
#include <fstream>
#include <string>
#include <vector>
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

    // Read datasets
    std::ifstream file10("dataset/data_10.txt");  // Replace with your file name
    std::vector<int> numbers_10;
    std::string line;

    if (file10.is_open()) {
        while (getline(file10, line)) {
            // Convert line to int and add to vector
            numbers_10.push_back(stoi(line));
        }
        file10.close();
    } else {
        std::cout << "Unable to open file";
    }

    std::ifstream file100("dataset/data_100.txt");  // Replace with your file name
    std::vector<int> numbers_100;

    if (file100.is_open()) {
        while (getline(file100, line)) {
            // Convert line to int and add to vector
            numbers_100.push_back(stoi(line));
        }
        file100.close();
    } else {
        std::cout << "Unable to open file";
    }
    
    std::ifstream file1000("dataset/data_1000.txt");  // Replace with your file name
    std::vector<int> numbers_1000;

    if (file1000.is_open()) {
        while (getline(file1000, line)) {
            // Convert line to int and add to vector
            numbers_1000.push_back(stoi(line));
        }
        file1000.close();
    } else {
        std::cout << "Unable to open file";
    }

    std::ifstream file10000("dataset/data_10000.txt");  // Replace with your file name
    std::vector<int> numbers_10000;

    if (file10000.is_open()) {
        while (getline(file10000, line)) {
            // Convert line to int and add to vector
            numbers_10000.push_back(stoi(line));
        }
        file10000.close();
    } else {
        std::cout << "Unable to open file";
    }

    std::ifstream file100000("dataset/data_100000.txt");  // Replace with your file name
    std::vector<int> numbers_100000;


    if (file100000.is_open()) {
        while (getline(file100000, line)) {
            // Convert line to int and add to vector
            numbers_100000.push_back(stoi(line));
        }
        file100000.close();
    } else {
        std::cout << "Unable to open file";
    }


	//===================================//  AVL TREE  //===================================//


    AVLTree<int> tree;



    // insert
    tree.insert(10);
    tree.insert(20);
    tree.insert(30);
    tree.insert(40);
    tree.insert(50);
    tree.insert(25);


    // Tree10
    start = std::chrono::steady_clock::now();
    AVLTree<int> tree10;
    for (int num : numbers_10){
        tree10.insert(num);
    }
    stop = std::chrono::steady_clock::now();
    difference_in_time = stop - start;
    // change to seconds
    difference_in_seconds = double(difference_in_time.count());
    cout << "Time taken to build AVL tree with 10 nodes is : " << difference_in_seconds << " seconds" << endl;

    // search
    // get a start time. insert this line where you want the time measurement begins.
    start = std::chrono::steady_clock::now();

    tree10.search(numbers_10[7]);

    // get a stop time. insert this line where you want the time measurement begins.
    stop = std::chrono::steady_clock::now();
    // get the difference
    difference_in_time = stop - start;
    // change to seconds
    difference_in_seconds = double(difference_in_time.count());
    cout << "Time taken by AVL search with 10 nodes is : " << difference_in_seconds << " seconds" << endl;
    //maximum
    // get a start time. insert this line where you want the time measurement begins.
    start = std::chrono::steady_clock::now();

    tree10.maximum();

    // get a stop time. insert this line where you want the time measurement begins.
    stop = std::chrono::steady_clock::now();
    // get the difference
    difference_in_time = stop - start;
    // change to seconds
    difference_in_seconds = double(difference_in_time.count());
    cout << "Time taken by AVL maximum with 10 nodes is : " << difference_in_seconds << " seconds" << endl;
    //minimum
    // get a start time. insert this line where you want the time measurement begins.
    start = std::chrono::steady_clock::now();

    tree10.minimum();

    // get a stop time. insert this line where you want the time measurement begins.
    stop = std::chrono::steady_clock::now();
    // get the difference
    difference_in_time = stop - start;
    // change to seconds
    difference_in_seconds = double(difference_in_time.count());
    cout << "Time taken by AVL minimum with 10 nodes is : " << difference_in_seconds << " seconds" << endl;



    // Tree100
    // insert from datasets
    start = std::chrono::steady_clock::now();
    AVLTree<int> tree100;
    for (int num : numbers_100) {
        tree100.insert(num);
    }
    stop = std::chrono::steady_clock::now();
    difference_in_time = stop - start;
    // change to seconds
    difference_in_seconds = double(difference_in_time.count());
    cout << "Time taken to build AVL tree with 100 nodes is : " << difference_in_seconds << " seconds" << endl;

    // search
    // get a start time. insert this line where you want the time measurement begins.
    start = std::chrono::steady_clock::now();

    tree100.search(numbers_100[7]);

    // get a stop time. insert this line where you want the time measurement begins.
    stop = std::chrono::steady_clock::now();
    // get the difference
    difference_in_time = stop - start;
    // change to seconds
    difference_in_seconds = double(difference_in_time.count());
    cout << "Time taken by AVL search with 100 nodes is : " << difference_in_seconds << " seconds" << endl;
    //maximum
    // get a start time. insert this line where you want the time measurement begins.
    start = std::chrono::steady_clock::now();

    tree100.maximum();

    // get a stop time. insert this line where you want the time measurement begins.
    stop = std::chrono::steady_clock::now();
    // get the difference
    difference_in_time = stop - start;
    // change to seconds
    difference_in_seconds = double(difference_in_time.count());
    cout << "Time taken by AVL maximum with 100 nodes is : " << difference_in_seconds << " seconds" << endl;
    //minimum
    // get a start time. insert this line where you want the time measurement begins.
    start = std::chrono::steady_clock::now();

    tree100.minimum();

    // get a stop time. insert this line where you want the time measurement begins.
    stop = std::chrono::steady_clock::now();
    // get the difference
    difference_in_time = stop - start;
    // change to seconds
    difference_in_seconds = double(difference_in_time.count());
    cout << "Time taken by AVL minimum with 100 nodes is : " << difference_in_seconds << " seconds" << endl;

    // Tree1000
    // insert from datasets
    start = std::chrono::steady_clock::now();
    AVLTree<int> tree1000;
    for (int num : numbers_1000) {
        tree1000.insert(num);
    }
    stop = std::chrono::steady_clock::now();
    difference_in_time = stop - start;
    // change to seconds
    difference_in_seconds = double(difference_in_time.count());
    cout << "Time taken to build AVL tree with 1000 nodes is : " << difference_in_seconds << " seconds" << endl;

    // search
    // get a start time. insert this line where you want the time measurement begins.
    start = std::chrono::steady_clock::now();

    tree1000.search(numbers_1000[7]);

    // get a stop time. insert this line where you want the time measurement begins.
    stop = std::chrono::steady_clock::now();
    // get the difference
    difference_in_time = stop - start;
    // change to seconds
    difference_in_seconds = double(difference_in_time.count());
    cout << "Time taken by AVL search with 1000 nodes is : " << difference_in_seconds << " seconds" << endl;
    //maximum
    // get a start time. insert this line where you want the time measurement begins.
    start = std::chrono::steady_clock::now();

    tree1000.maximum();

    // get a stop time. insert this line where you want the time measurement begins.
    stop = std::chrono::steady_clock::now();
    // get the difference
    difference_in_time = stop - start;
    // change to seconds
    difference_in_seconds = double(difference_in_time.count());
    cout << "Time taken by AVL maximum with 1000 nodes is : " << difference_in_seconds << " seconds" << endl;
    //minimum
    // get a start time. insert this line where you want the time measurement begins.
    start = std::chrono::steady_clock::now();

    tree1000.minimum();

    // get a stop time. insert this line where you want the time measurement begins.
    stop = std::chrono::steady_clock::now();
    // get the difference
    difference_in_time = stop - start;
    // change to seconds
    difference_in_seconds = double(difference_in_time.count());
    cout << "Time taken by AVL minimum with 1000 nodes is : " << difference_in_seconds << " seconds" << endl;

    // Tree10000
    // insert from datasets
    start = std::chrono::steady_clock::now();
    AVLTree<int> tree10000;
    for (int num : numbers_10000) {
        tree10000.insert(num);
    }
    stop = std::chrono::steady_clock::now();
    difference_in_time = stop - start;
    // change to seconds
    difference_in_seconds = double(difference_in_time.count());
    cout << "Time taken to build AVL tree with 10000 nodes is : " << difference_in_seconds << " seconds" << endl;

    // search
    // get a start time. insert this line where you want the time measurement begins.
    start = std::chrono::steady_clock::now();

    tree10000.search(numbers_10000[7]);

    // get a stop time. insert this line where you want the time measurement begins.
    stop = std::chrono::steady_clock::now();
    // get the difference
    difference_in_time = stop - start;
    // change to seconds
    difference_in_seconds = double(difference_in_time.count());
    cout << "Time taken by AVL search with 10000 nodes is : " << difference_in_seconds << " seconds" << endl;
    //maximum
    // get a start time. insert this line where you want the time measurement begins.
    start = std::chrono::steady_clock::now();

    tree10000.maximum();

    // get a stop time. insert this line where you want the time measurement begins.
    stop = std::chrono::steady_clock::now();
    // get the difference
    difference_in_time = stop - start;
    // change to seconds
    difference_in_seconds = double(difference_in_time.count());
    cout << "Time taken by AVL maximum with 10000 nodes is : " << difference_in_seconds << " seconds" << endl;
    //minimum
    // get a start time. insert this line where you want the time measurement begins.
    start = std::chrono::steady_clock::now();

    tree10000.minimum();

    // get a stop time. insert this line where you want the time measurement begins.
    stop = std::chrono::steady_clock::now();
    // get the difference
    difference_in_time = stop - start;
    // change to seconds
    difference_in_seconds = double(difference_in_time.count());
    cout << "Time taken by AVL minimum with 10000 nodes is : " << difference_in_seconds << " seconds" << endl;

    //Tree100000
    // insert from datasets
    start = std::chrono::steady_clock::now();
    AVLTree<int> tree100000;
    for (int num : numbers_100000) {
        tree100000.insert(num);
    }
    stop = std::chrono::steady_clock::now();
    difference_in_time = stop - start;
    // change to seconds
    difference_in_seconds = double(difference_in_time.count());
    cout << "Time taken to build AVL tree with 100000 nodes is : " << difference_in_seconds << " seconds" << endl;

    // search
    // get a start time. insert this line where you want the time measurement begins.
    start = std::chrono::steady_clock::now();

    tree100000.search(numbers_100000[7]);

    // get a stop time. insert this line where you want the time measurement begins.
    stop = std::chrono::steady_clock::now();
    // get the difference
    difference_in_time = stop - start;
    // change to seconds
    difference_in_seconds = double(difference_in_time.count());
    cout << "Time taken by AVL search with 100000 nodes is : " << difference_in_seconds << " seconds" << endl;
    //maximum
    // get a start time. insert this line where you want the time measurement begins.
    start = std::chrono::steady_clock::now();

    tree100000.maximum();

    // get a stop time. insert this line where you want the time measurement begins.
    stop = std::chrono::steady_clock::now();
    // get the difference
    difference_in_time = stop - start;
    // change to seconds
    difference_in_seconds = double(difference_in_time.count());
    cout << "Time taken by AVL maximum with 100000 nodes is : " << difference_in_seconds << " seconds" << endl;
    //minimum
    // get a start time. insert this line where you want the time measurement begins.
    start = std::chrono::steady_clock::now();

    tree100000.minimum();

    // get a stop time. insert this line where you want the time measurement begins.
    stop = std::chrono::steady_clock::now();
    // get the difference
    difference_in_time = stop - start;
    // change to seconds
    difference_in_seconds = double(difference_in_time.count());
    cout << "Time taken by AVL minimum with 100000 nodes is : " << difference_in_seconds << " seconds" << endl;


    // print
    cout << "Inorder traversal of the constructed AVL tree is \n";
    tree.inOrder();
    cout << endl;
	
	
	
	
	//===================================//  RED BLACK TREE  //===================================//


    RBTree<int> treeRB;



    // insert
    treeRB.insert(10);
    treeRB.insert(20);
    treeRB.insert(30);
    treeRB.insert(40);
    treeRB.insert(50);
    treeRB.insert(25);


    // treeRB10
    start = std::chrono::steady_clock::now();
    RBTree<int> treeRB10;
    for (int num : numbers_10){
        treeRB10.insert(num);
    }
    stop = std::chrono::steady_clock::now();
    difference_in_time = stop - start;
    // change to seconds
    difference_in_seconds = double(difference_in_time.count());
    cout << "Time taken to build RB tree with 10 nodes is : " << difference_in_seconds << " seconds" << endl;

    // search
    // get a start time. insert this line where you want the time measurement begins.
    start = std::chrono::steady_clock::now();

    treeRB10.search(numbers_10[7]);

    // get a stop time. insert this line where you want the time measurement begins.
    stop = std::chrono::steady_clock::now();
    // get the difference
    difference_in_time = stop - start;
    // change to seconds
    difference_in_seconds = double(difference_in_time.count());
    cout << "Time taken by RB search with 10 nodes is : " << difference_in_seconds << " seconds" << endl;
    //maximum
    // get a start time. insert this line where you want the time measurement begins.
    start = std::chrono::steady_clock::now();

    treeRB10.maximum();

    // get a stop time. insert this line where you want the time measurement begins.
    stop = std::chrono::steady_clock::now();
    // get the difference
    difference_in_time = stop - start;
    // change to seconds
    difference_in_seconds = double(difference_in_time.count());
    cout << "Time taken by RB maximum with 10 nodes is : " << difference_in_seconds << " seconds" << endl;
    //minimum
    // get a start time. insert this line where you want the time measurement begins.
    start = std::chrono::steady_clock::now();

    treeRB10.minimum();

    // get a stop time. insert this line where you want the time measurement begins.
    stop = std::chrono::steady_clock::now();
    // get the difference
    difference_in_time = stop - start;
    // change to seconds
    difference_in_seconds = double(difference_in_time.count());
    cout << "Time taken by RB minimum with 10 nodes is : " << difference_in_seconds << " seconds" << endl;



    // treeRB100
    // insert from datasets
    start = std::chrono::steady_clock::now();
    RBTree<int> treeRB100;
    for (int num : numbers_100) {
        treeRB100.insert(num);
    }
    stop = std::chrono::steady_clock::now();
    difference_in_time = stop - start;
    // change to seconds
    difference_in_seconds = double(difference_in_time.count());
    cout << "Time taken to build RB tree with 100 nodes is : " << difference_in_seconds << " seconds" << endl;

    // search
    // get a start time. insert this line where you want the time measurement begins.
    start = std::chrono::steady_clock::now();

    treeRB100.search(numbers_100[7]);

    // get a stop time. insert this line where you want the time measurement begins.
    stop = std::chrono::steady_clock::now();
    // get the difference
    difference_in_time = stop - start;
    // change to seconds
    difference_in_seconds = double(difference_in_time.count());
    cout << "Time taken by RB search with 100 nodes is : " << difference_in_seconds << " seconds" << endl;
    //maximum
    // get a start time. insert this line where you want the time measurement begins.
    start = std::chrono::steady_clock::now();

    treeRB100.maximum();

    // get a stop time. insert this line where you want the time measurement begins.
    stop = std::chrono::steady_clock::now();
    // get the difference
    difference_in_time = stop - start;
    // change to seconds
    difference_in_seconds = double(difference_in_time.count());
    cout << "Time taken by RB maximum with 100 nodes is : " << difference_in_seconds << " seconds" << endl;
    //minimum
    // get a start time. insert this line where you want the time measurement begins.
    start = std::chrono::steady_clock::now();

    treeRB100.minimum();

    // get a stop time. insert this line where you want the time measurement begins.
    stop = std::chrono::steady_clock::now();
    // get the difference
    difference_in_time = stop - start;
    // change to seconds
    difference_in_seconds = double(difference_in_time.count());
    cout << "Time taken by RB minimum with 100 nodes is : " << difference_in_seconds << " seconds" << endl;



    // treeRB1000
    // insert from datasets
    start = std::chrono::steady_clock::now();
    RBTree<int> treeRB1000;
    for (int num : numbers_1000) {
        treeRB1000.insert(num);
    }
    stop = std::chrono::steady_clock::now();
    difference_in_time = stop - start;
    // change to seconds
    difference_in_seconds = double(difference_in_time.count());
    cout << "Time taken to build RB tree with 1000 nodes is : " << difference_in_seconds << " seconds" << endl;

    // search
    // get a start time. insert this line where you want the time measurement begins.
    start = std::chrono::steady_clock::now();

    treeRB1000.search(numbers_1000[7]);

    // get a stop time. insert this line where you want the time measurement begins.
    stop = std::chrono::steady_clock::now();
    // get the difference
    difference_in_time = stop - start;
    // change to seconds
    difference_in_seconds = double(difference_in_time.count());
    cout << "Time taken by RB search with 1000 nodes is : " << difference_in_seconds << " seconds" << endl;
    //maximum
    // get a start time. insert this line where you want the time measurement begins.
    start = std::chrono::steady_clock::now();

    treeRB1000.maximum();

    // get a stop time. insert this line where you want the time measurement begins.
    stop = std::chrono::steady_clock::now();
    // get the difference
    difference_in_time = stop - start;
    // change to seconds
    difference_in_seconds = double(difference_in_time.count());
    cout << "Time taken by RB maximum with 1000 nodes is : " << difference_in_seconds << " seconds" << endl;
    //minimum
    // get a start time. insert this line where you want the time measurement begins.
    start = std::chrono::steady_clock::now();

    treeRB1000.minimum();

    // get a stop time. insert this line where you want the time measurement begins.
    stop = std::chrono::steady_clock::now();
    // get the difference
    difference_in_time = stop - start;
    // change to seconds
    difference_in_seconds = double(difference_in_time.count());
    cout << "Time taken by RB minimum with 1000 nodes is : " << difference_in_seconds << " seconds" << endl;



    // treeRB10000
    // insert from datasets
    start = std::chrono::steady_clock::now();
    RBTree<int> treeRB10000;
    for (int num : numbers_10000) {
        treeRB10000.insert(num);
    }
    stop = std::chrono::steady_clock::now();
    difference_in_time = stop - start;
    // change to seconds
    difference_in_seconds = double(difference_in_time.count());
    cout << "Time taken to build RB tree with 10000 nodes is : " << difference_in_seconds << " seconds" << endl;

    // search
    // get a start time. insert this line where you want the time measurement begins.
    start = std::chrono::steady_clock::now();

    treeRB10000.search(numbers_10000[7]);

    // get a stop time. insert this line where you want the time measurement begins.
    stop = std::chrono::steady_clock::now();
    // get the difference
    difference_in_time = stop - start;
    // change to seconds
    difference_in_seconds = double(difference_in_time.count());
    cout << "Time taken by RB search with 10000 nodes is : " << difference_in_seconds << " seconds" << endl;
    //maximum
    // get a start time. insert this line where you want the time measurement begins.
    start = std::chrono::steady_clock::now();

    treeRB10000.maximum();

    // get a stop time. insert this line where you want the time measurement begins.
    stop = std::chrono::steady_clock::now();
    // get the difference
    difference_in_time = stop - start;
    // change to seconds
    difference_in_seconds = double(difference_in_time.count());
    cout << "Time taken by RB maximum with 10000 nodes is : " << difference_in_seconds << " seconds" << endl;
    //minimum
    // get a start time. insert this line where you want the time measurement begins.
    start = std::chrono::steady_clock::now();

    treeRB10000.minimum();

    // get a stop time. insert this line where you want the time measurement begins.
    stop = std::chrono::steady_clock::now();
    // get the difference
    difference_in_time = stop - start;
    // change to seconds
    difference_in_seconds = double(difference_in_time.count());
    cout << "Time taken by RB minimum with 10000 nodes is : " << difference_in_seconds << " seconds" << endl;



    //treeRB100000
    // insert from datasets
    start = std::chrono::steady_clock::now();
    RBTree<int> treeRB100000;
    for (int num : numbers_100000) {
        treeRB100000.insert(num);
    }
    stop = std::chrono::steady_clock::now();
    difference_in_time = stop - start;
    // change to seconds
    difference_in_seconds = double(difference_in_time.count());
    cout << "Time taken to build RB tree with 100000 nodes is : " << difference_in_seconds << " seconds" << endl;

    // search
    // get a start time. insert this line where you want the time measurement begins.
    start = std::chrono::steady_clock::now();

    treeRB100000.search(numbers_100000[7]);

    // get a stop time. insert this line where you want the time measurement begins.
    stop = std::chrono::steady_clock::now();
    // get the difference
    difference_in_time = stop - start;
    // change to seconds
    difference_in_seconds = double(difference_in_time.count());
    cout << "Time taken by RB search with 100000 nodes is : " << difference_in_seconds << " seconds" << endl;
    //maximum
    // get a start time. insert this line where you want the time measurement begins.
    start = std::chrono::steady_clock::now();

    treeRB100000.maximum();

    // get a stop time. insert this line where you want the time measurement begins.
    stop = std::chrono::steady_clock::now();
    // get the difference
    difference_in_time = stop - start;
    // change to seconds
    difference_in_seconds = double(difference_in_time.count());
    cout << "Time taken by RB maximum with 100000 nodes is : " << difference_in_seconds << " seconds" << endl;
    //minimum
    // get a start time. insert this line where you want the time measurement begins.
    start = std::chrono::steady_clock::now();

    treeRB100000.minimum();

    // get a stop time. insert this line where you want the time measurement begins.
    stop = std::chrono::steady_clock::now();
    // get the difference
    difference_in_time = stop - start;
    // change to seconds
    difference_in_seconds = double(difference_in_time.count());
    cout << "Time taken by RB minimum with 100000 nodes is : " << difference_in_seconds << " seconds" << endl;


    // print
    cout << "Inorder traversal of the constructed RB tree is \n";
    tree.inOrder();
    cout << endl;
	
	
	
	
	
	
    /*%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%*/
   
    return 0;
}
