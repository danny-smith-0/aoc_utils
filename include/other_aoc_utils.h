#ifndef OTHER_AOC_UTILS_H
#define OTHER_AOC_UTILS_H

#include <aoc_typedefs.h>
#include <iostream>
#include <algorithm>

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

int count_bools_t_2d(bools_t_2d bools)
{
    int count = 0;
    for (auto row: bools)
        for (auto my_bool : row)
            count += my_bool ? 1 : 0;

    return count;
}

bools_t_2d coords_to_bools(coords_t_vec path, size_t max_dimension = 1001, size_t min_dimension_display = 0)
{
    // min_dimension_display = min_dimension_display == 0 ? max_dimension :
    bools_t_2d map (max_dimension, bools_t(max_dimension, false));
    size_t my_max_idx = 0;
    for (auto coords : path)
    {
        my_max_idx = std::max(my_max_idx, std::max(coords.first, coords.second));
        if(my_max_idx + 1 > max_dimension)
        {
            std::cout << "my_max_idx + 1 > max_dimension! ---  " << my_max_idx << " + 1 > " << max_dimension << ". Uh-oh\n";
            return bools_t_2d();
        }
        map[coords.first][coords.second] = true;
    }

    //Remove unused parts of the map
    min_dimension_display = std::max(min_dimension_display, my_max_idx + 1);
    map = bools_t_2d(map.begin(), map.begin() + min_dimension_display);
    for (auto& line : map)
        line = bools_t(line.begin(), line.begin() + min_dimension_display);
    return map;
}

size_t steps_between_cells(coords_t cell1, coords_t cell2)
{
    sll diff = cell1.first - cell2.first;
    size_t first_steps  = static_cast<size_t>(std::abs(diff));
    diff = cell1.second - cell2.second;
    size_t second_steps = static_cast<size_t>(std::abs(diff));
    size_t out = first_steps + second_steps;
    return out;
}

#endif // OTHER_AOC_UTILS_H
