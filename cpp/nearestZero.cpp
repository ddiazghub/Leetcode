#include <vector>
#include <unordered_set>
#include <utility>
#include <algorithm>
#include <iostream>

constexpr int MAX_MATRIX_LENGTH = 10000;

/**
 * Find the distance of a cell in a matrix to the nearest zero.
 */
inline void updateCell(std::vector<std::vector<int>> &mat, std::vector<std::vector<int>> &distances, int i, int j) {
    int dist;

    if (mat[i][j] == 0)
        dist = 0;
    else
        dist = 1 + std::min({
            distances[i + 2][j + 1],
            distances[i][j + 1],
            distances[i + 1][j + 2],
            distances[i + 1][j]
        });

    distances[i + 1][j + 1] = dist;
}

/**
 * Find the distance of all cells in a matrix to the nearest zero.
 */
std::vector<std::vector<int>> updateMatrix(std::vector<std::vector<int>> &mat) {
    int n = mat.size(), m = mat[0].size();

    if (n == 1 && m == 1 && mat[0][0] == 0)
        return {{0}};

    std::vector<std::vector<int>> distances(n + 2, std::vector<int>(m + 2, MAX_MATRIX_LENGTH));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            updateCell(mat, distances, i, j);
        }
    }

    for (int i = n - 1; i > -1; i--) {
        for (int j = m - 1; j > -1; j--) {
            updateCell(mat, distances, i, j);
        }
    }

    std::vector<std::vector<int>> output(n, std::vector<int>(m));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            output[i][j] = distances[i + 1][j + 1];
        }
    }

    return output;
}

int main() {
    std::vector<std::vector<int>> matrix{{0, 1, 0, 1, 1}, {1, 1, 0, 0, 1}, {0, 0, 0, 1, 0}, {1, 0, 1, 1, 1}, {1, 0, 0, 0, 1}};
    std::vector<std::vector<int>> distances = updateMatrix(matrix);

    for (auto &row : distances) {
        for (int distance : row) {
            std::cout << distance << ',';
        }

        std::cout << '\n';
    }
}