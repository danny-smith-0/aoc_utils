#include <other_aoc_utils.h>

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
