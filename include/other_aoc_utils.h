#ifndef OTHER_AOC_UTILS_H
#define OTHER_AOC_UTILS_H

#include <aoc_typedefs.h>
#include <iostream>
#include <algorithm>

// Replicate the matlab colon 2:5 ==> {2,3,4,5} and 6:4 ==> {6,5,4}
ints_t matlab_colon(int first, int last);

// Count the number of true's in a bools_t_2d
int count_bools_t_2d(bools_t_2d bools);

// Given a path (vector or coordinates), make a bools_t_2d with true set for the path locations
bools_t_2d coords_to_bools(coords_t_vec path, size_t max_dimension = 1001, size_t min_dimension_display = 0);

// Get the number of non-diagonal steps between two coordinates
size_t steps_between_cells(coords_t cell1, coords_t cell2);


template <typename T>
void print_T_2d(T output, bool with_comma = false, bool null_is_space = false)
{
    std::cout << print_T_2d_to_string(output, with_comma, null_is_space);
}

template <typename T>
std::string print_T_2d_to_string(T output, bool with_comma = false, bool null_is_space = false)
{
    std::stringstream ss;
    for (auto row : output)
    {
        for (auto val : row)
        {
            if (null_is_space && val == 0) { ss << " "; }
            else                           { ss << val; }
            if (with_comma) { ss << ","; }
        }
        ss << std::endl;
    }
    return ss.str();
}


template <typename T>
size_t largest_subvector(std::vector<std::vector<T>> vec_2d)
{
    size_t max_size = 0;
    for (auto vec : vec2d)
        max_size = vec.size() > max_size ? vec.size() : max_size;
    return max_size;
}

template <typename T>
size_t smallest_subvector(std::vector<std::vector<T>> vec_2d)
{
    size_t max_size = SIZE_MAX;
    for (auto vec : vec2d)
        max_size = vec.size() < max_size ? vec.size() : max_size;
    return max_size;
}


template <typename T>
void results(T test_result, T expected_test_result, T real_result)
{
    std::cout << "Test result is " << test_result;
    if (test_result == expected_test_result) { std::cout << ". Passed!\nReal result is " << real_result << std::endl; }
    else                                     { std::cout << ". Failed. Looking for " << expected_test_result << "\n";  }
}

template <typename T>
bool results(T result, T expected_result)
{
    std::cout << "Test result is " << result;
    if (result == expected_result) { std::cout << ". Passed!\n Now running the real input\n";          return true;  }
    else                           { std::cout << ". Failed. Looking for " << expected_result << "\n"; return false; }
}

#endif // OTHER_AOC_UTILS_H
