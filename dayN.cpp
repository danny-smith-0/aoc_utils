#include <advent_of_code.h>

ints_t_2d parse(strings_t input)
{
    ints_t_2d out;
    return out;
}

sll part1(strings_t input)
{
    sll out = 0;
    return out;
}

sll part2(strings_t input)
{
    sll out = 0;
    return out;
}

int main ()
{
    std::string day_string = "14";
    strings_t test_data = get_strings_from_file("../inputs/day" + day_string + "_test.txt");
    strings_t real_data = get_strings_from_file("../inputs/day" + day_string + ".txt");
    std::cout << "Day " << day_string << std::endl;


    sll results_test_1 = part1(test_data);
    sll results_real_1 = part1(real_data);
    sll expected_test_result_1 = 0;

    sll results_test_2 = part2(test_data);
    sll results_real_2 = part2(real_data);
    sll expected_test_result_2 = 0;

    results(results_test_1, expected_test_result_1, results_real_1);
    results(results_test_2, expected_test_result_2, results_real_2);

    return 0;
}
