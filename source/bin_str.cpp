#include <bin_str.h>
#include <cmath> //pow

ull binstring_to_value(std::string binstr)
{
    ull value = 0;
    for (std::string::reverse_iterator riter = binstr.rbegin(); riter != binstr.rend(); ++riter)
        if (*riter == '1')
            value += static_cast<ull>( std::pow(2, std::distance(binstr.rbegin(), riter)) );
    return value;
}

std::string hexchar_to_binstring(char hexchar)
{
    switch (hexchar)
    {
        case '0':           { return "0000"; }
        case '1':           { return "0001"; }
        case '2':           { return "0010"; }
        case '3':           { return "0011"; }
        case '4':           { return "0100"; }
        case '5':           { return "0101"; }
        case '6':           { return "0110"; }
        case '7':           { return "0111"; }
        case '8':           { return "1000"; }
        case '9':           { return "1001"; }
        case 'A': case 'a': { return "1010"; }
        case 'B': case 'b': { return "1011"; }
        case 'C': case 'c': { return "1100"; }
        case 'D': case 'd': { return "1101"; }
        case 'E': case 'e': { return "1110"; }
        case 'F': case 'f': { return "1111"; }
        default : { }
    }
    return "";
}
