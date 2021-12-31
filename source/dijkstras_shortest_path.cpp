#include <dijkstras_shortest_path.h>

#include <iostream>
#include <algorithm> // std::sort
#include <chrono>

using namespace std::chrono;

namespace dijkstra
{

class UnvistedVertexSorter
{
    public:
    // UnvistedVertexSorter::UnvistedVertexSorter();
    UnvistedVertexSorter::UnvistedVertexSorter(VertexTable& vertex_table_ref) : vertex_table(vertex_table_ref) {}
    bool operator() (coords_t ii,coords_t jj) { return ( vertex_table[ii].distance_from_start < vertex_table[jj].distance_from_start ); }
    VertexTable& vertex_table;
};

void shortest_path(VertexTable& vertex_table, ints_t_2d const& distance_map)
{
    std::chrono::steady_clock::time_point t1 = std::chrono::steady_clock::now();

    std::map<coords_t, coords_t_vec> neighbors = get_neighboring_cells(distance_map);

    coords_t_vec unvisited_vertices;

    // Add an entry for every cell in the map to the vertex_table
    for (auto [vert_key,v] : neighbors)
    {
        vertex_table[vert_key] = VertexInfo();
        unvisited_vertices.push_back(vert_key);
    }

    coords_t start (0, 0);
    vertex_table[start].distance_from_start = 0;


    UnvistedVertexSorter my_sorter(vertex_table);
    std::sort(unvisited_vertices.begin(), unvisited_vertices.end(), my_sorter);

    while (!unvisited_vertices.empty())
    {
        if (unvisited_vertices.size() % 500 == 0)
        {
            std::chrono::steady_clock::time_point t2 = std::chrono::steady_clock::now();
            duration<double> time_span = duration_cast<duration<double>>(t2 - t1);
            std::cout << "Unvisited vertices: " << unvisited_vertices.size() << " - " << time_span.count() / 3600.0 << " hours.\n";
        }
        // The vector is sorted by distance from the start
        coords_t current_vert = unvisited_vertices.front();
        uint64_t current_dist = vertex_table[current_vert].distance_from_start;

        for (auto neighbor : neighbors[current_vert])
        {
            uint64_t distance = current_dist + distance_map[neighbor.first][neighbor.second];
            VertexInfo& neighbor_info = vertex_table[neighbor];
            if (distance < neighbor_info.distance_from_start)
            {
                neighbor_info.distance_from_start = distance;
                neighbor_info.previous_vertex = current_vert;
            }
        }

        // Remove the current vertex and sort the remaining
        unvisited_vertices.erase(unvisited_vertices.begin());
        if (!unvisited_vertices.empty())
            std::sort(unvisited_vertices.begin(), unvisited_vertices.end(), my_sorter);
    }


    std::chrono::steady_clock::time_point t2 = std::chrono::steady_clock::now();
    duration<double> time_span = duration_cast<duration<double>>(t2 - t1);
    std::cout << "Finished in << " << time_span.count() / 3600.0 << " hours.\n";
}

std::map<coords_t, coords_t_vec> get_neighboring_cells(ints_t_2d const& distance_map, bool diagonals)
{
    std::map<coords_t, coords_t_vec> neighbors;

    for (size_t ii = 0; ii < distance_map.size(); ++ii)
    {
        for (size_t jj = 0; jj < distance_map[0].size(); ++jj)
        {
            coords_t current (ii, jj);
            coords_t_vec current_neighbors;
            bool first_row = ii == 0;
            bool last__row = ii == distance_map.size() - 1;
            bool first_col = jj == 0;
            bool last__col = jj == distance_map[0].size() - 1;

            if (!first_row) current_neighbors.push_back( coords_t(ii - 1, jj    ));
            if (!last__row) current_neighbors.push_back( coords_t(ii + 1, jj    ));
            if (!first_col) current_neighbors.push_back( coords_t(ii,     jj - 1));
            if (!last__col) current_neighbors.push_back( coords_t(ii,     jj + 1));

            if (diagonals)
            {
                if (!first_row && !first_col) current_neighbors.push_back( coords_t(ii - 1, jj - 1));
                if (!first_row && !last__col) current_neighbors.push_back( coords_t(ii - 1, jj + 1));
                if (!last__row && !last__col) current_neighbors.push_back( coords_t(ii + 1, jj + 1));
                if (!last__row && !first_col) current_neighbors.push_back( coords_t(ii + 1, jj - 1));
            }

            neighbors[current] = current_neighbors;
        }
    }

    return neighbors;
}

}  // namespace dij
