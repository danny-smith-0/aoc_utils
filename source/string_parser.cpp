#include <string_parser.h>

#include <sstream>
#include <fstream>  // std::ifstream


strings_t get_strings_from_file(const std::string& file_path)
{
    strings_t strings;
    std::ifstream file_stream ("../inputs/day3_test.txt");
    std::string line;
    while (std::getline(file_stream, line))
        strings.push_back(line);
    return strings;
}


bool find_space_in_string(std::string str_in, size_t* index)
{
    size_t found = str_in.find(" ");
    if(found != std::string::npos)
    {
        *index = found;
        return true;
    }
    return false;
}

std::string string_before_space(std::string string_in, size_t space_index)
{
    return string_in.substr(0, space_index);
}

std::string string_after_space(std::string string_in, size_t space_index)
{
    return string_in.substr(space_index + 1, string_in.size() - 1);
}

std::vector<int> substrings_to_ints(std::string string, std::string delimeter)
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

strings_t substrings_to_strings(std::string string, std::string delimeter)
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
