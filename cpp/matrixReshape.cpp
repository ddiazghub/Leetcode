#include <vector>

std::vector<std::vector<int>> matrixReshape(std::vector<std::vector<int>> &mat, int rows, int cols) {
    int m = mat.size();
    int n = mat[0].size();

    if (m * n == rows * cols) {
        std::vector<std::vector<int>> reshaped(rows, std::vector<int>(cols));
        int row = 0;
        int col = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                reshaped[row][col] = mat[i][j];
                col++;

                if (col == cols) {
                    col = 0;
                    row++;
                }
            }
        }

        return reshaped;
    } else
        return mat;
}

int main() {

}