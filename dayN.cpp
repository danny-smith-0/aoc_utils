#include <iostream> //std::cout
#include <fstream>  // std::ifstream
#include <string>
#include <sstream>
#include <vector>
#include <array>

#include <string_parser.h>
#include <other_aoc_utils.h>

typedef std::vector<int> ints_t;


int main ()
{
    std::ifstream input_test ("../inputs/dayN_test.txt");
    std::ifstream input_real ("../inputs/dayN.txt");


    int results_test_1 = 0;
    int results_real_1 = 0;

    int results_test_2 = 0;
    int results_real_2 = 0;

    results(results_test_1, 0, results_real_1);
    results(results_test_2, 0, results_real_2);

    return 0;
}
