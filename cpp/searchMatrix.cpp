#include <vector>
#include <utility>
#include <iostream>

/**
 * Convert a 1D array index to 2D array coordinates.
 */
inline std::pair<int, int> to2d(int index, int m) {
    return std::make_pair(index / m, index % m);
} 

/**
 * Search a value in a matrix using binary search.
 */
bool searchMatrix(std::vector<std::vector<int>> &matrix, int target) {
    int n = matrix.size();
    int m = matrix[0].size();
    int start = 0;
    int end = n * m;

    while (start < end) {
        int middle = start + (end - start) / 2;
        auto [i, j] = to2d(middle, m);
        int value = matrix[i][j];

        if (target > value)
            start = middle + 1;
        else if (target < value)
            end = middle;
        else
            return true;
    }

    auto [i, j] = to2d(start, m);

    return i > -1 && i < n && j > -1 && j < m  && matrix[i][j] == target;
}

int main() {
    std::vector<std::vector<int>> matrix{
        {1, 3, 5, 7},
        {10, 11, 16, 20},
        {23, 30, 34, 60}
    };

    std::cout << searchMatrix(matrix, 13) << '\n';
}