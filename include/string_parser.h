#ifndef STRING_PARSER_H
#define STRING_PARSER_H

#include <aoc_typedefs.h>

namespace aoc
{
    strings_t get_strings_from_file(const std::string& file_path);

    bool find_delimeter_in_string(std::string const& str_in, size_t* index_out, std::string const& delimeter = " ");  // Used to be find_space_in_string
    std::string string_before_delimeter(std::string const& string_in, size_t delimeter_index = SIZE_MAX);  // Use to be string_before_space
    std::string string_after_delimeter(std::string const& string_in, size_t delimeter_index = SIZE_MAX);  // Use to be string_after_space

    ints_t    substrings_to_ints(std::string const& string, std::string const& delimeter);
    strings_t substrings_to_strings(std::string const& string, std::string const& delimeter);

    ints_t_2d strings_of_digits_to_ints(strings_t const& input);

    bool compare_sorted_strings(std::string str1, std::string str2);

    void unique_sorted_string(std::string& input_str);
}

#endif // STRING_PARSER_H
