#include <vector>
#include <iostream>
#include <numeric>
#include <algorithm>

/**
 * Traverse a spiral in a matrix while storing the elements in a vector.
 */
inline void fillSpiral(std::vector<std::vector<int>> &matrix, std::vector<int> &output, int depth) {
    int rows = matrix.size() - depth;
    int cols = matrix[0].size() - depth;
    
    for (int i = depth; i < cols; i++)
        output.push_back(matrix[depth][i]);

    for (int i = depth + 1; i < rows; i++)
        output.push_back(matrix[i][cols - 1]);

    if (depth < rows - 1) {
        for (int i = cols - 2; i >= depth; i--)
            output.push_back(matrix[rows - 1][i]);
    }

    if (depth < cols - 1) {
        for (int i = rows - 2; i > depth; i--)
            output.push_back(matrix[i][depth]);
    }
}

/**
 * Return a vector containing the elements of a matrix in spiral order.
 */
std::vector<int> spiralOrder(std::vector<std::vector<int>>& matrix) {
    std::vector<int> output;
    int maxDepth = std::min(matrix.size(), matrix[0].size());

    for (int depth = 0; depth < (maxDepth + 1) / 2; depth++)
        fillSpiral(matrix, output, depth);
    
    return output;
}

int main() {
    std::vector<std::vector<int>> matrix{{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};
    auto result = spiralOrder(matrix);

    for (int num: result)
        std::cout << num << ", ";
}