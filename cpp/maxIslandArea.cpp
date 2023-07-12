#include <vector>
#include <set>
#include <queue>
#include <iostream>

/**
 * Return the maximum area of an island in grid.
 */
int maxAreaOfIsland(std::vector<std::vector<int>> &grid, std::set<std::pair<int, int>> &traversed, std::pair<int, int> start) {
    std::queue<std::pair<int, int>> next;
    next.push(start);
    int n = grid.size();
    int m = grid[0].size();
    int area = 0;

    while (next.size() > 0) {
        auto position = next.front();
        auto [i, j] = position;

        if (traversed.find(position) == traversed.end()) {
            if (i > -1 && i < n && j > -1 && j < m && grid[i][j] == 1) {
                traversed.insert(position);
                area++;

                next.push(std::make_pair(i + 1, j));
                next.push(std::make_pair(i - 1, j));
                next.push(std::make_pair(i, j + 1));
                next.push(std::make_pair(i, j - 1));
            }
        }

        next.pop();
    }

    return area;
}

/**
 * Return the maximum area of an island in grid.
 */
int maxAreaOfIsland(std::vector<std::vector<int>> &grid) {
    int n = grid.size();
    int m = grid[0].size();
    std::set<std::pair<int, int>> traversed;
    int max = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            auto position = std::make_pair(i, j);

            if (grid[i][j] == 1 && traversed.find(position) == traversed.end()) {
                int area = maxAreaOfIsland(grid, traversed, position);
                max = std::max(max, area);
            }
        }
    }

    return max;
}

int main() {
    std::vector<std::vector<int>> grid{
        {0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0},
        {0, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 1, 0, 0, 1, 1, 0, 0, 1, 0, 1, 0, 0},
        {0, 1, 0, 0, 1, 1, 0, 0, 1, 1, 1, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0}
    };

    std::cout << maxAreaOfIsland(grid) << '\n';
}