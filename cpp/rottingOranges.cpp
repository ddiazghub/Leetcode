#include <vector>
#include <algorithm>
#include <iostream>

constexpr int MAX_CELLS = 100;

enum CellType {
    Empty,
    Fresh,
    Rotten
};

inline int findMinutes(std::vector<std::vector<int>> &grid, std::vector<std::vector<int>> &minutes, int i, int j) {
    int mins;
    CellType cell = static_cast<CellType>(grid[i][j]);

    switch (cell) {
        case Empty:
            mins = MAX_CELLS;
            break;
        case Fresh:
            mins = 1 + std::min({
                minutes[i + 2][j + 1],
                minutes[i][j + 1],
                minutes[i + 1][j + 2],
                minutes[i + 1][j],
            });

            break;
        case Rotten:
            mins = 0;
    }

    return mins;
}

/**
 * I tried doing DP but ended up with a huge hack. At least it works.
 */
int orangesRotting(std::vector<std::vector<int>> &grid) {
    int n = grid.size(), m = grid[0].size();
    int length = std::max(n, m);
    std::vector<std::vector<int>> minutes(n + 2, std::vector<int>(m + 2, MAX_CELLS));
    int neededMins = -1;

    for (int k = 0; k < length / 2; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                minutes[i + 1][j + 1] = findMinutes(grid, minutes, i, j);
            }
        }

        for (int i = n - 1; i > - 1; i--) {
            for (int j = m - 1; j > -1; j--) {
                minutes[i + 1][j + 1] = findMinutes(grid, minutes, i, j);
            }
        }
    }

    for (int i = n - 1; i > -1; i--) {
        for (int j = m - 1; j > -1; j--) {
            int mins = findMinutes(grid, minutes, i, j);
            minutes[i + 1][j + 1] = mins;

            if (static_cast<CellType>(grid[i][j]) != Empty)
                neededMins = std::max(neededMins, mins);
        }
    }

    if (neededMins == -1)
        return 0;
    else if (neededMins >= MAX_CELLS)
        return -1;

    return neededMins;
}

int main() {
    std::vector<std::vector<int>> grid{{2,0,1,1,1,1,1,1,1,1},{1,0,1,0,0,0,0,0,0,1},{1,0,1,0,1,1,1,1,0,1},{1,0,1,0,1,0,0,1,0,1},{1,0,1,0,1,0,0,1,0,1},{1,0,1,0,1,1,0,1,0,1},{1,0,1,0,0,0,0,1,0,1},{1,0,1,1,1,1,1,1,0,1},{1,0,0,0,0,0,0,0,0,1},{1,1,1,1,1,1,1,1,1,1}};
    std::cout << orangesRotting(grid) << '\n';
}