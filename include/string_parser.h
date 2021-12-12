#ifndef STRING_PARSER_H
#define STRING_PARSER_H

#include <aoc_typedefs.h>

strings_t get_strings_from_file(const std::string& file_path);

bool find_space_in_string(std::string str_in, size_t* index);
std::string string_before_space(std::string string_in, size_t space_index);
std::string string_after_space(std::string string_in, size_t space_index);

ints_t    substrings_to_ints(std::string string, std::string delimeter);
strings_t substrings_to_strings(std::string string, std::string delimeter);

ints_t_2d strings_of_digits_to_ints(strings_t input);

bool compare_sorted_strings(std::string str1, std::string str2);

#endif // STRING_PARSER_H
