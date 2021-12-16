#ifndef STRING_PARSER_H
#define STRING_PARSER_H

#include <aoc_typedefs.h>

strings_t get_strings_from_file(const std::string& file_path);

bool find_space_in_string(std::string const& str_in, size_t* index);
std::string string_before_space(std::string const& string_in, size_t space_index);
std::string string_after_space(std::string const& string_in, size_t space_index);

ints_t    substrings_to_ints(std::string const& string, std::string const& delimeter);
strings_t substrings_to_strings(std::string const& string, std::string const& delimeter);

ints_t_2d strings_of_digits_to_ints(strings_t const& input);

bool compare_sorted_strings(std::string str1, std::string str2);

#endif // STRING_PARSER_H
