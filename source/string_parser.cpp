#include <string_parser.h>

#include <sstream>
#include <fstream>  // std::ifstream
#include <algorithm> // sort

strings_t get_strings_from_file(const std::string& file_path)
{
    strings_t strings;
    std::ifstream file_stream (file_path);
    std::string line;
    while (std::getline(file_stream, line))
        strings.push_back(line);
    return strings;
}


bool find_space_in_string(std::string const& str_in, size_t* index)
{
    size_t found = str_in.find(" ");
    if(found != std::string::npos)
    {
        *index = found;
        return true;
    }
    return false;
}

std::string string_before_space(std::string const& string_in, size_t space_index)
{
    return string_in.substr(0, space_index);
}

std::string string_after_space(std::string const& string_in, size_t space_index)
{
    return string_in.substr(space_index + 1, string_in.size() - 1);
}

std::vector<int> substrings_to_ints(std::string const& string, std::string const& delimeter)
{
    std::vector<int> ints;
    std::stringstream s_stream(string);
    while(s_stream.good())
    {
        std::string substr;
        std::getline(s_stream, substr, *(delimeter.c_str())); //get first string delimited by comma
        if(substr == "")
            continue;
        ints.push_back(std::stoi(substr));
    }
    return ints;
}

strings_t substrings_to_strings(std::string const& string, std::string const& delimeter)
{
    strings_t strings;
    std::stringstream s_stream(string);
    while(s_stream.good())
    {
        std::string substr;
        std::getline(s_stream, substr, *(delimeter.c_str())); //get first string delimited by comma
        if(substr == "")
            continue;
        strings.push_back(substr);
    }
    return strings;
}

ints_t_2d strings_of_digits_to_ints(strings_t const& input)
{
    ints_t_2d out;
    for (auto number_string : input)
    {
        ints_t line;
        for (auto digit : number_string)
        {
            line.push_back(digit - '0'); //Find distance from the char for zero.
        }
        out.push_back(line);
    }
    return out;
}

bool compare_sorted_strings(std::string str1, std::string str2)
{
    std::sort(str1.begin(), str1.end());
    std::sort(str2.begin(), str2.end());
    return str1 == str2;
}
