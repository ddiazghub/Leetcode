#include <vector>
#include <iostream>

/**
 * Rotate a matrix at a given index.
 */
void rotateAt(std::vector<std::vector<int>>& matrix, int i, int j) {
    int max = matrix.size() - i - 1;
    int offset = j - i;
    int temp = matrix[i][j];

    matrix[i][j] = matrix[max - offset][i];
    matrix[max - offset][i] = matrix[max][max - offset];
    matrix[max][max - offset] = matrix[j][max];
    matrix[j][max] = temp;
}

/**
 * Rotate a matrix.
 */
void rotate(std::vector<std::vector<int>>& matrix) {
    int n = matrix.size();

    for (int i = 0; i < n / 2; i++) {
        for (int j = i; j < n - i - 1; j++)
            rotateAt(matrix, i, j);
    }
}

int main() {
    std::vector<std::vector<int>> matrix{{5, 1, 9, 11}, {2, 4, 8, 10}, {13, 3, 6, 7}, {15, 14, 12, 16}};
    rotate(matrix);

    for (auto &row: matrix) {
        for (int num: row) {
            std::cout << num << ',';
        }

        std::cout << '\n';
    }
}