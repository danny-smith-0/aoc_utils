#ifndef PATH_ALGORITHMS_H
#define PATH_ALGORITHMS_H

#include <limits.h>
#include <map>
#include <optional>

#include <aoc_typedefs.h>

namespace dijkstra
{
    struct VertexInfo
    {
        uint64_t distance_from_start = std::numeric_limits<uint64_t>::max();
        std::optional<coords_t> previous_vertex = std::nullopt;
    };

    typedef std::map<coords_t, VertexInfo> VertexTable;

    void shortest_path(VertexTable& vertex_table, ints_t_2d const& distance_map);

    std::map<coords_t, coords_t_vec> get_neighboring_cells(ints_t_2d const& distance_map, bool diagonals = false);

} // namespace dijkstra


#endif // PATH_ALGORITHMS_H
