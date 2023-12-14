#include <chrono>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "TreeStruct/RNG.h"
#include "TreeStruct/AVL.h"

void processFile(long num)
{
    std::chrono::time_point<std::chrono::steady_clock> start, stop;
    std::chrono::duration<double> difference_in_time;
    double difference_in_seconds; // Holds the final run time

    // get a start time
    start = std::chrono::steady_clock::now();

    // Read datasets
    std::ifstream file("dataset/data_" + std::to_string(num) + ".txt");
    std::vector<int> numbers;
    std::string line;

    if (file.is_open())
    {
        while (getline(file, line))
        {
            // Convert line to int and add to vector
            numbers.push_back(stoi(line));
        }
        file.close();
    }
    else
    {
        std::cout << "Unable to open file";
        return;
    }

    // get a stop time
    stop = std::chrono::steady_clock::now();

    // get the difference in NANO seconds
    difference_in_time = stop - start;
    // change to nanoseconds
    auto difference_in_ns = std::chrono::duration_cast<std::chrono::nanoseconds>(difference_in_time);
    std::cout << "For data scale " << num << ", Time taken for reading data is : " << difference_in_ns.count() << " nanoseconds" << std::endl;

    // change to seconds
    // difference_in_seconds = double(difference_in_time.count());
    // std::cout << "Time taken by program is : " << difference_in_seconds << " seconds" << std::endl;

    // std::cout << "Numbers: ";
    //  for (int num : numbers)
    //{
    //      std::cout << num << " ";
    //  }
    //  std::cout << std::endl;
}

void processAVLTree(int num)
{
    // Read datasets
    std::ifstream file("dataset/data_" + std::to_string(num) + ".txt");
    std::vector<int> numbers;
    std::string line;

    if (file.is_open())
    {
        while (getline(file, line))
        {
            // Convert line to int and add to vector
            numbers.push_back(stoi(line));
        }
        file.close();
    }
    else
    {
        std::cout << "Unable to open file";
        return;
    }

    std::chrono::time_point<std::chrono::steady_clock> start, stop;
    std::chrono::duration<double> difference_in_time;
    double difference_in_seconds; // Holds the final run time

    // Tree
    start = std::chrono::steady_clock::now();
    AVLTree<int> tree;
    tree.insert(1234);
    for (int num : numbers)
    {
        tree.insert(num);
    }
    stop = std::chrono::steady_clock::now();
    difference_in_time = stop - start;
    // change to nanoseconds
    auto difference_in_ns = std::chrono::duration_cast<std::chrono::nanoseconds>(difference_in_time);
    std::cout << "For data scale " << num << ", Time taken for inserting data is : " << difference_in_ns.count() << " nanoseconds" << std::endl;
    // change to seconds
    // difference_in_seconds = double(difference_in_time.count());
    // std::cout << "Time taken to build AVL tree with " << num << " nodes is : " << difference_in_seconds << " seconds" << std::endl;

    // search
    start = std::chrono::steady_clock::now();
    tree.search(numbers[7]);
    stop = std::chrono::steady_clock::now();
    difference_in_time = stop - start;
    // change to nanoseconds
    difference_in_ns = std::chrono::duration_cast<std::chrono::nanoseconds>(difference_in_time);
    std::cout << "For data scale " << num << ", Time taken for searching data is : " << difference_in_ns.count() << " nanoseconds" << std::endl;
    // difference_in_seconds = double(difference_in_time.count());
    // std::cout << "Time taken by AVL search with " << num << " nodes is : " << difference_in_seconds << " seconds" << std::endl;

    // maximum
    start = std::chrono::steady_clock::now();
    tree.maximum();
    stop = std::chrono::steady_clock::now();
    difference_in_time = stop - start;
    // change to nanoseconds
    difference_in_ns = std::chrono::duration_cast<std::chrono::nanoseconds>(difference_in_time);
    std::cout << "For data scale " << num << ", Time taken for finding maxium is : " << difference_in_ns.count() << " nanoseconds" << std::endl;
    // difference_in_seconds = double(difference_in_time.count());
    // std::cout << "Time taken by AVL maximum with " << num << " nodes is : " << difference_in_seconds << " seconds" << std::endl;

    // minimum
    start = std::chrono::steady_clock::now();
    tree.minimum();
    stop = std::chrono::steady_clock::now();
    difference_in_time = stop - start;
    // change to nanoseconds
    difference_in_ns = std::chrono::duration_cast<std::chrono::nanoseconds>(difference_in_time);
    std::cout << "For data scale " << num << ", Time taken for finding minium is : " << difference_in_ns.count() << " nanoseconds" << std::endl;
    // difference_in_seconds = double(difference_in_time.count());
    // std::cout << "Time taken by AVL minimum with " << num << " nodes is : " << difference_in_seconds << " seconds" << std::endl;
}
int main()
{
    long num = 10, i;
    for (i = 0; i < 7; ++i)
    {
        processFile(num);
        processAVLTree(num);
        num *= 10;
    }
    // std::cout << "Precision: "<< std::chrono::steady_clock::period::num<< "/"<< std::chrono::steady_clock::period::den<< " s" << std::endl;
    return 0;
}