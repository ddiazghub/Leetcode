#include <vector>

int diagonalSum(std::vector<std::vector<int>> &mat) {
    int sum = 0;
    int size = mat.size();
    int size1 = mat.size() - 1;

    for (int i = 0; i < size; i++) {
        sum += mat[i][i] + mat[i][size1 - i];
    }

    if (size % 2 > 0)
        sum -= mat[size / 2][size / 2];

    return sum;
}

int main() {
    
}