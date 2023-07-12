#include <vector>

/**
 * Number of unique paths to the end of a grid.
 */
int uniquePaths(int m, int n) {
    std::vector<std::vector<int>> table(m + 1, std::vector<int>(n + 1));
    table[m][n - 1] = 1;

    for (int i = m - 1; i > -1; i--) {
        for (int j = n - 1; j > -1; j--) {
            table[i][j] = table[i + 1][j] + table[i][j + 1];
        }
    }

    return table[0][0];
}

int main() {

}