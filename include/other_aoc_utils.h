#ifndef OTHER_AOC_UTILS_H
#define OTHER_AOC_UTILS_H

#include <aoc_typedefs.h>

ints_t matlab_colon(int first, int last);

template <typename T>
void results(T test_result, T expected_test_result, T real_result)
{
    std::cout << "Test result is " << test_result;
    if (test_result == expected_test_result)
    {
        std::cout << ". Passed!\n";
        std::cout << "Real result is " << real_result << std::endl;
    }
    else
        std::cout << ". Failed. Looking for " << expected_test_result << "\n";
}

#endif // OTHER_AOC_UTILS_H
