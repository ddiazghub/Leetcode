#include <vector>
#include <algorithm>

/**
 * Given a triangle array, return the minimum path sum from top to bottom.
 */
int minimumTotal(std::vector<std::vector<int>> &triangle) {
    int height = triangle.size();
    std::vector<std::vector<int>> pathSums(height + 1);
    pathSums[height].resize(height + 1);

    for (int row = height - 1; row > -1; row--) {
        int cols = row + 1;
        pathSums[row].resize(cols);

        for (int col = 0; col < cols; col++) {
            int min = std::min(pathSums[row + 1][col], pathSums[row + 1][col + 1]);
            pathSums[row][col] = triangle[row][col] + min;
        }
    }

    return pathSums[0][0];
}

int main() {
    
}