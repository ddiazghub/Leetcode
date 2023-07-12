#include <vector>

/**
 * Generate a pascal's triangle with the given number of rows.
 */
std::vector<std::vector<int>> generate(int numRows) {
    std::vector<std::vector<int>> triangle{{1}};

    for (int i = 1; i < numRows; i++) {
        std::vector<int> row;
        std::vector<int> &lastRow = triangle[i - 1];

        for (int j = 0; j <= i; j++) {
            if (j > 0 && j < i)
                row.push_back(lastRow[j - 1] + lastRow[j]);
            else
                row.push_back(1);
        }

        triangle.push_back(row);
    }

    return triangle;
}

int main() {

}