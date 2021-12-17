#include <other_aoc_utils.h>

// Replicate the matlab colon 2:5 ==> {2,3,4,5} and 6:4 ==> {6,5,4}
ints_t matlab_colon(int first, int last)
{
    int incr = first < last ? 1 : -1;
    ints_t ints;
    for (int ii = first; ; ii += incr)
    {
        ints.push_back(ii);
        if ( ii == last)
            break;
    }
    return ints;
}

// Count the number of true's in a bools_t_2d
int count_bools_t_2d(bools_t_2d bools)
{
    int count = 0;
    for (auto row: bools)
        for (auto my_bool : row)
            count += my_bool ? 1 : 0;

    return count;
}

// Given a path (vector or coordinates), make a bools_t_2d with true set for the path locations
bools_t_2d coords_to_bools(coords_t_vec path, size_t max_dimension /*= 1001*/, size_t min_dimension_display /*= 0*/)
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

// Get the number of non-diagonal steps between two coordinates
size_t steps_between_cells(coords_t cell1, coords_t cell2)
{
    sll diff = cell1.first - cell2.first;
    size_t first_steps  = static_cast<size_t>(std::abs(diff));
    diff = cell1.second - cell2.second;
    size_t second_steps = static_cast<size_t>(std::abs(diff));
    size_t out = first_steps + second_steps;
    return out;
}
