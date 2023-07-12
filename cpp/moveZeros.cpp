#include <vector>
#include <iostream>
#include <algorithm>

/**
 * Advance pointer until the next zero element is found.
 */
void seekNextZero(std::vector<int> &nums, unsigned int &seeker) {
    while (seeker < nums.size() && nums[seeker] != 0)
        seeker++;
}

/**
 * Advance pointer until the next non zero element is found.
 */
void seekNextNonZero(std::vector<int> &nums, unsigned int &seeker) {
    while (seeker < nums.size() && nums[seeker] == 0)
        seeker++;
}

/**
 * Move all zeros to the end of an array.
 */
void moveZeroes(std::vector<int> &nums) {
    unsigned int n = nums.size();

    if (n == 1)
        return;
    
    unsigned int end = 0;
    seekNextZero(nums, end);
    unsigned int current = end + 1;
    seekNextNonZero(nums, current);

    while (current < n && end < n) {
        nums[end] = nums[current];
        nums[current] = 0;
        end = current;
        current++;
        seekNextNonZero(nums, current);
    }
}

int main() {
    std::vector<int> nums{0, 1, 0, 3, 12};
    moveZeroes(nums);
    
    for (int num: nums) {
        std::cout << num << ',';
    }

    std::cout << '\n';
}