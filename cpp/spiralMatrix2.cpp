#include <vector>

/**
 * Set a matrix cell with the next value in the sequence and increment the sequence.
 */
inline void setCell(std::vector<std::vector<int>> &matrix, int i, int j, int &value) {
    matrix[i][j] = value;
    value++;
}

/**
 * Fill a matrix with values in spiral order.
 */
inline void fillSpiral(std::vector<std::vector<int>> &matrix, int depth, int n, int &current) {
    int end = n - depth - 1;
    
    for (int i = depth; i < end; i++) {
        setCell(matrix, depth, i, current);
    }

    for (int i = depth; i < end; i++) {
        setCell(matrix, i, end, current);
    }

    for (int i = end; i > depth; i--) {
        setCell(matrix, end, i, current);
    }

    for (int i = end; i > depth; i--) {
        setCell(matrix, i, depth, current);
    }
}

/**
 * Create a spiral matrix of the given size.
 */
std::vector<std::vector<int>> generateMatrix(int n) {
    if (n == 1)
        return std::vector<std::vector<int>> {{ 1 }};
    
    std::vector<std::vector<int>> matrix(n, std::vector<int>(n));
    int current = 1;
    int half = n / 2;

    if (n % 2 > 0)
        matrix[half][half] = n * n;
        
    for (int depth = 0; depth < half; depth++) {
        fillSpiral(matrix, depth, n, current);
    }

    return matrix;
}

int main() {

}