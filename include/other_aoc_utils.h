#ifndef OTHER_AOC_UTILS_H
#define OTHER_AOC_UTILS_H

#include <aoc_typedefs.h>
#include <iostream>

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

void print_ints_t_2d(ints_t_2d output, bool with_comma = false)
{
    for (auto row : output)
    {
        for (auto val : row)
        {
            std::cout << val;
            if (with_comma)
                std::cout << ",";
        }
        std::cout << std::endl;
    }
}

template <typename T>
void print_T_2d(T output, bool with_comma = false, bool null_is_space = false)
{
    for (auto row : output)
    {
        for (auto val : row)
        {
            if (null_is_space && val == 0) { std::cout << " "; }
            else                           { std::cout << val; }
            if (with_comma) { std::cout << ","; }
        }
        std::cout << std::endl;
    }
}

int count_bools_t_2d(bools_t_2d bools)
{
    int count = 0;
    for (auto row: bools)
        for (auto my_bool : row)
            count += my_bool ? 1 : 0;

    return count;
}

#endif // OTHER_AOC_UTILS_H
