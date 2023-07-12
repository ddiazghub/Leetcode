#include <vector>
#include <algorithm>
#include <iostream>

/**
 * Check if the square that starts at coordinate (row, col) is still a square when extended to the specified length offset.
 */
inline bool isSquare(std::vector<std::vector<char>> &matrix, int row, int col, int length) {
    for (int i = row; i < row + length; i++) {
        if (matrix[i][col + length] == '0')
            return false;
    }

    for (int j = col; j <= col + length; j++) {
        if (matrix[row + length][j] == '0')
            return false;
    }

    return true;
}

/**
 * Given an m x n binary matrix filled with 0's and 1's, find the largest square containing only 1's and return its area.
 */
int maximalSquare(std::vector<std::vector<char>> &matrix) {
    int rows = matrix.size();
    int cols = matrix[0].size();
    int maxLen = 0;

    for (int row = 0; row < rows - maxLen; row++) {
        for (int col = 0; col < cols - maxLen; col++) {
            if (matrix[row][col] == '1') {
                int length = 1;

                while (row + length < rows && col + length < cols && isSquare(matrix, row, col, length))
                    length++;

                maxLen = std::max(maxLen, length);
            }
        }
    }

    return maxLen * maxLen;
}

int main() {
    std::vector<std::vector<char>> matrix{
        {'1', '0', '1', '0', '0'},
        {'1', '0', '1', '1', '1'},
        {'1', '1', '1', '1', '1'},
        {'1', '0', '0', '1', '0'}
    };
    
    std::cout << maximalSquare(matrix) << '\n';
}