#include <vector>
#include <algorithm>
#include <iostream>

/**
 * You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security systems connected and it will automatically contact the police if two adjacent houses were broken into on the same night.
 * Given an integer array nums representing the amount of money of each house, return the maximum amount of money you can rob tonight without alerting the police.
 */
int rob(std::vector<int> &nums) {
    int n = nums.size();
    std::vector<int> maxMoney(n + 1);
    maxMoney[n - 1] = nums[n - 1];

    for (int i = n - 2; i > -1; i--)
        maxMoney[i] = std::max(nums[i] + maxMoney[i + 2], maxMoney[i + 1]);

    return maxMoney[0];
}

int main() {
    std::vector<int> nums{1, 2, 3, 1};
    std::cout << rob(nums) << '\n';
}