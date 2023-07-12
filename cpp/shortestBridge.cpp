#include <vector>
#include <unordered_set>
#include <utility>
#include <queue>
#include <limits>
#include <algorithm>
#include <tuple>

constexpr int COLUMN_BITMASK = (1 << 16) - 1;

/**
 * Struct representing an island.
 */
struct Island {
    /**
     * A hashset containing the positions of all tiles belonging to the island compressed as bitmasks.
     */
    std::unordered_set<int> tiles;

    /**
     * Tiles of water directly adjacent to the island compressed as bitmasks.
     */
    std::unordered_set<int> frontier;
};


/**
 * Converts a position to a bitmask.
 */
inline int bitmask(int row, int column) {
    return (row << 16) + column;
}

/**
 * Converts a bitmask to a position.
 */
inline std::pair<int, int> parseBitmask(int mask) {
    return std::make_pair(mask >> 16, mask & COLUMN_BITMASK);
}

/**
 * Traverses an island in a grid from the given start point.
 * Returns an island struct containing all tiles belonging to the island and all adjacent tiles of water.
 */
Island traverseIsland(std::vector<std::vector<int>> &grid, std::pair<int, int> start) {
    Island island;
    std::vector<std::pair<int, int>> stack{start};
    int lastIndex = grid.size() - 1;

    while (stack.size() > 0) {
        auto [row, column] = stack.back();
        stack.pop_back();

        if (row < 0 || row > lastIndex || column < 0 || column > lastIndex)
            continue;

        int mask = bitmask(row, column);

        if (grid[row][column] == 0) {
            island.frontier.insert(mask);
            continue;
        }

        if (island.tiles.find(mask) == island.tiles.end()) {
            island.tiles.insert(mask);
            stack.push_back(std::make_pair(row + 1, column));
            stack.push_back(std::make_pair(row - 1, column));
            stack.push_back(std::make_pair(row, column + 1));
            stack.push_back(std::make_pair(row, column - 1));
        }
    }

    return island;
}

/**
 * Return the shortest number of tiles needed to make a bridge from the given island to another one.
 */
int shortestBridge(std::vector<std::vector<int>> &grid, Island &island) {
    std::unordered_set<int> traversed;
    std::queue<std::tuple<int, int, int>> queue;

    for (int bitmask : island.frontier) {
        auto [row, column] = parseBitmask(bitmask);
        queue.push(std::make_tuple(row, column, 0));
    }

    int lastIndex = grid.size() - 1;

    while (queue.size() > 0) {
        auto [row, column, depth] = queue.front();
        queue.pop();

        if (row < 0 || row > lastIndex || column < 0 || column > lastIndex)
            continue;

        int mask = bitmask(row, column);
        int tile = grid[row][column];

        if (tile == 1) {
            if (island.tiles.find(mask) == island.tiles.end())
                return depth;

            continue;
        } else {
            if (traversed.find(mask) == traversed.end()) {
                traversed.insert(mask);
                depth++;
                queue.push(std::make_tuple(row + 1, column, depth));
                queue.push(std::make_tuple(row - 1, column, depth));
                queue.push(std::make_tuple(row, column + 1, depth));
                queue.push(std::make_tuple(row, column - 1, depth));
            }
        }
    }

    return std::numeric_limits<int>::max();
}

/**
 * Return the shortest number of tiles needed to make a bridge between 2 islands in a grid.
 */
int shortestBridge(std::vector<std::vector<int>> &grid) {
    int n = grid.size();

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == 1) {
                std::pair<int, int> start{i, j};
                Island island = traverseIsland(grid, start);
                
                return shortestBridge(grid, island);
            }
        }
    }

    // Impossible
    return -1;
}

int main() {

}