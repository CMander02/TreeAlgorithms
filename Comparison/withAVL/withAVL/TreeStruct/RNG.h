#ifndef RANDNUM_H
#define RANDNUM_H

#include <vector>
#include <random>
#include <algorithm>
#include <ctime>

class RNG
{
private:
    std::mt19937 generator;

public:
    // Constructor
    RNG() : generator(static_cast<unsigned int>(std::time(nullptr)))
    {
    }

    // Generate random integers
    std::vector<int> generate(size_t count, int min, int max, bool sort)
    {
        std::vector<int> numbers;
        std::uniform_int_distribution<int> distribution(min, max);

        for (size_t i = 0; i < count; ++i)
        {
            numbers.push_back(distribution(generator));
        }

        if (sort)
        {
            std::sort(numbers.begin(), numbers.end());
        }

        return numbers;
    }

    // Generate random long numbers
    std::vector<long> generate(size_t count, long min, long max, bool sort)
    {
        std::vector<long> numbers;
        std::uniform_int_distribution<long> distribution(min, max);

        for (size_t i = 0; i < count; ++i)
        {
            numbers.push_back(distribution(generator));
        }

        if (sort)
        {
            std::sort(numbers.begin(), numbers.end());
        }

        return numbers;
    }
};

#endif // RANDNUM_H
