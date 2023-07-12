#include <vector>
#include <limits>

/**
 * Find the sum of the path from top left to bottom right in a grid which minimizes the sum of all elements.
 */
int minPathSum(std::vector<std::vector<int>> &grid) {
    int m = grid.size(), n = grid[0].size();
    std::vector<std::vector<int>> table(m + 1, std::vector<int>(n + 1, std::numeric_limits<int>::max()));
    table[m][n - 1] = 0;

    for (int i = m - 1; i > -1; i--) {
        for (int j = n - 1; j > -1; j--) {
            table[i][j] = grid[i][j] + std::min(table[i + 1][j], table[i][j + 1]);
        }
    }

    return table[0][0];
}