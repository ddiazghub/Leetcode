#include <vector>

int countNegatives(std::vector<std::vector<int>> &grid) {
    int n = grid.size(), m = grid[0].size();
    int count = 0;
    int j = m - 1;

    for (int i = 0; i < n; i++) {
        while (j > -1 && grid[i][j] < 0)
            j--;

        count += m - j - 1;
    }

    return count;
}

int main() {
    
}