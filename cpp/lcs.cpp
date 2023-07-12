#include <string>
#include <vector>

/**
 * Finding the longest common subsequence between 2 strings.
 */
int longestCommonSubsequence(std::string text1, std::string text2) {
    int n = text1.size(), m = text2.size();
    std::vector<std::vector<int>> memory(n + 1, std::vector<int>(m + 1));

    for (int i = 0; i < n + 1; i++) {
        for (int j = 0; j < m + 1; j++) {
            if (i == 0 || j == 0)
                memory[i][j] = 0;
            else if (text1[i - 1] == text2[j - 1])
                memory[i][j] = memory[i - 1][j - 1] + 1;
            else
                memory[i][j] = std::max(memory[i - 1][j], memory[i][j - 1]);
        }
    }

    return memory[n][m];
}

int main() {}