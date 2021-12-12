#include <advent_of_code.h>

int main ()
{
    std::string day_string = "10";
    strings_t test_data = get_strings_from_file("../inputs/day" + day_string + "_test.txt");
    strings_t real_data = get_strings_from_file("../inputs/day" + day_string + ".txt");
    std::cout << "Day " << day_string << std::endl;


    int results_test_1 = 0;
    int results_real_1 = 0;

    int results_test_2 = 0;
    int results_real_2 = 0;

    results(results_test_1, 0, results_real_1);
    results(results_test_2, 0, results_real_2);

    return 0;
}
