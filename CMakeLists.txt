cmake_minimum_required (VERSION 3.14)
project (advent_of_code_utilities)

add_library( aoc_utils
    source/bin_str.cpp
    source/other_aoc_utils.cpp
    source/string_parser.cpp
)

target_include_directories ( aoc_utils
    PUBLIC
    include
)
