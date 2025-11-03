#include "paths.h"
#include "plots.h"
#include <cmath>
#include <iostream>
#include <climits>

// Helper: check if a point is inside any plot (uses plots vector only for reading)
static bool inside_any_plot(int x, int z, const std::vector<Plot> &plots) {
    for (size_t i = 0; i < plots.size(); ++i) {
        const Plot &p = plots[i];
        // treat only strict interior as blocked; allow stepping on plot borders so roads can skirt plots
        if (x > p.origin.x && x < p.bound.x && z > p.origin.z && z < p.bound.z)
            return true;
    }
    return false;
}

// Custom BFS implementation that avoids C++ STL containers (no std::queue, std::map, std::vector, etc.)
// Uses plain C-style arrays and a simple open-addressing hash table for visited/parent lookup.
std::vector<mcpp::Coordinate> find_path(mcpp::MinecraftConnection &mc,
                                        const mcpp::Coordinate &start,
                                        const mcpp::Coordinate &goal,
                                        const std::vector<Plot> &plots) {
    std::vector<mcpp::Coordinate> empty;

    if (start.x == goal.x && start.z == goal.z)
        return {start};

    // Increase limits to allow larger searches; values are powers of two where appropriate.
    const int MAX_STEPS = 100000;
    const int MAX_NODES = 131072; // capacity for nodes visited
    const int HT_SIZE = 262144; // power-of-two hash table size

    struct Node { int x; int z; int parent; };

    Node *nodes = new Node[MAX_NODES];
    int nodes_cnt = 0;

    // Simple hash table arrays. ht_val = -1 means empty slot.
    int *ht_keyx = new int[HT_SIZE];
    int *ht_keyz = new int[HT_SIZE];
    int *ht_val  = new int[HT_SIZE];
    for (int i = 0; i < HT_SIZE; ++i) { ht_keyx[i] = INT_MIN; ht_keyz[i] = INT_MIN; ht_val[i] = -1; }

    auto hash_index = [&](int x, int z) -> unsigned int {
        unsigned int hx = static_cast<unsigned int>(x) * 73856093u;
        unsigned int hz = static_cast<unsigned int>(z) * 19349663u;
        return (hx ^ hz) & (HT_SIZE - 1);
    };

    auto ht_find = [&](int x, int z) -> int {
        unsigned int h = hash_index(x, z);
        while (ht_val[h] != -1) {
            if (ht_keyx[h] == x && ht_keyz[h] == z) return ht_val[h];
            h = (h + 1) & (HT_SIZE - 1);
        }
        return -1;
    };

    auto ht_insert = [&](int x, int z, int val) -> bool {
        unsigned int h = hash_index(x, z);
        while (ht_val[h] != -1) {
            if (ht_keyx[h] == x && ht_keyz[h] == z) return false; // already exists
            h = (h + 1) & (HT_SIZE - 1);
        }
        ht_keyx[h] = x; ht_keyz[h] = z; ht_val[h] = val;
        return true;
    };

    // Simple circular queue of node indices
    int *queue = new int[MAX_NODES];
    int qh = 0, qt = 0;

    // Push start
    nodes[0].x = start.x; nodes[0].z = start.z; nodes[0].parent = -1;
    nodes_cnt = 1;
    ht_insert(start.x, start.z, 0);
    queue[qt] = 0; qt = (qt + 1) % MAX_NODES;

    const int dirs[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
    bool found = false;
    int found_idx = -1;
    int steps = 0;

    while (qh != qt && steps < MAX_STEPS) {
        int cur_idx = queue[qh];
        qh = (qh + 1) % MAX_NODES; // pop
        ++steps;

        int cx = nodes[cur_idx].x;
        int cz = nodes[cur_idx].z;

        if (cx == goal.x && cz == goal.z) { found = true; found_idx = cur_idx; break; }

        for (int d = 0; d < 4; ++d) {
            int nx = cx + dirs[d][0];
            int nz = cz + dirs[d][1];

            // skip points inside any plot, but allow stepping into the goal even if it lies inside a plot
            if (inside_any_plot(nx, nz, plots) && !(nx == goal.x && nz == goal.z)) continue;

            if (ht_find(nx, nz) != -1) continue; // already visited

            if (nodes_cnt >= MAX_NODES) continue; // out of capacity, skip

            // compute next queue index and ensure we don't overwrite head (full queue)
            int next_qt = (qt + 1) % MAX_NODES;
            if (next_qt == qh) continue; // queue full, skip

            nodes[nodes_cnt].x = nx;
            nodes[nodes_cnt].z = nz;
            nodes[nodes_cnt].parent = cur_idx;

            ht_insert(nx, nz, nodes_cnt);
            queue[qt] = nodes_cnt;
            qt = next_qt;
            ++nodes_cnt;
        }
    }

    if (!found) {
        std::cerr << "find_path: BFS failed to find path between (" << start.x << "," << start.z << ") and (" << goal.x << "," << goal.z << ").\n";
        delete[] nodes; delete[] ht_keyx; delete[] ht_keyz; delete[] ht_val; delete[] queue;
        return empty;
    }

    // Reconstruct path indices into a small dynamic array
    int *rev = new int[nodes_cnt];
    int rev_len = 0;
    int cur = found_idx;
    while (cur != -1 && rev_len < nodes_cnt) {
        rev[rev_len++] = cur;
        cur = nodes[cur].parent;
    }

    std::vector<mcpp::Coordinate> path;
    path.reserve(rev_len);

    for (int i = rev_len - 1; i >= 0; --i) {
        int idx = rev[i];
        int x = nodes[idx].x;
        int z = nodes[idx].z;
        try {
            mcpp::HeightMap hm = mc.getHeights({x, z}, {x, z});
            int y = hm.get_worldspace({x, z});
            path.push_back({x, y, z});
        } catch (...) {
            path.push_back({x, 64, z});
        }
    }

    delete[] nodes; delete[] ht_keyx; delete[] ht_keyz; delete[] ht_val; delete[] queue; delete[] rev;

    return path;
}
