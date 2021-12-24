#ifndef AOC_TYPEDEFS_H
#define AOC_TYPEDEFS_H

#include <string>
#include <vector>

typedef unsigned long long ull;
typedef signed long long sll;

typedef std::vector<int>    ints_t;
typedef std::vector<ints_t> ints_t_2d;
typedef std::vector<ints_t_2d> ints_t_3d;

typedef std::vector<ull>    ulls_t;
typedef std::vector<ulls_t> ulls_t_2d;
typedef std::vector<sll>    slls_t;
typedef std::vector<slls_t> slls_t_2d;

typedef std::vector<bool>    bools_t;
typedef std::vector<bools_t> bools_t_2d;
typedef std::vector<bools_t_2d> bools_t_3d;

typedef std::vector<std::string> strings_t;
typedef std::vector<strings_t>   strings_t_2d;

typedef std::pair<size_t, size_t> coords_t;
typedef std::vector<coords_t> coords_t_vec;

#endif // AOC_TYPEDEFS_H
