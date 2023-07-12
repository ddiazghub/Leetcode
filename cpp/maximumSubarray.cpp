#include <vector>
#include <algorithm>
#include <iostream>
#include <limits>

/**
 * Find the maximum sum of a sub array in an array.
 */
int maxSubArray(std::vector<int> &nums) {
    int n = nums.size();
    int max = nums[0];
    int current = nums[0];

    for (int i = 1; i < n; i++) {
        current = std::max(nums[i], nums[i] + current);
        max = std::max(max, current);
    }

    return max;
}

int main() {

}