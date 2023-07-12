#include <vector>
#include <iostream>

/**
 * Remove all duplicates from a sorted vector.
 */
int removeDuplicates(std::vector<int> &nums) {
    int unique = 1;

    for (unsigned int i = 1; i < nums.size(); i++) {
        if (nums[i] != nums[i - 1]) {
            nums[unique] = nums[i];
            unique++;
        }
    }

    nums.resize(unique);
    
    return unique;
}

int main() {
    std::vector<int> nums = {1, 1, 2};
    std::cout << removeDuplicates(nums) << '\n';
    
    for (int num: nums)
        std::cout << num << ",";
}