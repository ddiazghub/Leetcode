#include <vector>
#include <algorithm>
#include <limits>

/**
 * Given an n x n array of integers matrix, return the minimum sum of any falling path through matrix.
 * A falling path starts at any element in the first row and chooses the element in the next row that is either directly below or diagonally left/right. Specifically, the next element from position (row, col) will be (row + 1, col - 1), (row + 1, col), or (row + 1, col + 1).@brief 
 */
int minFallingPathSum(std::vector<std::vector<int>> &matrix) {
    int length = matrix.size();

    std::vector<std::vector<int>> pathSums(
        length + 1,
        std::vector<int>(
            length + 2,
            std::numeric_limits<int>::max()
        )
    );

    std::fill(pathSums.back().begin(), pathSums.back().end(), 0);
    
    for (int row = length - 1; row > -1; row--) {
        for (int col = 0; col < length; col++) {
            pathSums[row][col + 1] = matrix[row][col] + std::min({
                pathSums[row + 1][col],
                pathSums[row + 1][col + 1],
                pathSums[row + 1][col + 2]
            });
        }
    }

    return *std::min_element(pathSums[0].begin() + 1, pathSums[0].begin() + length + 1);
}

int main() {

}