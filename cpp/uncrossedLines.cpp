#include <vector>
#include <algorithm>
#include <iostream>
#include<array>

/**
 * Finding the longest common subsequence between 2 vectors of numbers.
 */
int lcs(std::vector<int> &nums1, std::vector<int> &nums2) {
    int n = nums1.size(), m = nums2.size();
    std::vector<std::vector<int>> memory(n + 1, std::vector<int>(m + 1));

    for (int i = 0; i < n + 1; i++) {
        for (int j = 0; j < m + 1; j++) {
            if (i == 0 || j == 0)
                memory[i][j] = 0;
            else if (nums1[i - 1] == nums2[j - 1])
                memory[i][j] = memory[i - 1][j - 1] + 1;
            else
                memory[i][j] = std::max(memory[i - 1][j], memory[i][j - 1]);
        }
    }

    return memory[n][m];
}

/**
 * This problem's description is extremely complicated so Im just gonna go ahead and say it's LCS.
 */
int maxUncrossedLines(std::vector<int>& nums1, std::vector<int>& nums2) {
    return lcs(nums1, nums2);
}

int main() {
    std::vector<int> nums1{1, 2, 4, 1, 4, 4, 3, 5, 5, 1, 4, 4, 4, 1, 4, 3, 4, 2, 4, 2};
    std::vector<int> nums2{2, 4, 1, 1, 3, 5, 2, 1, 5, 1, 2, 3, 3, 2, 1, 4, 1, 2, 5, 5};
    std::cout << maxUncrossedLines(nums1, nums2) << '\n';
}