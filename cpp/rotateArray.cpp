#include <vector>
#include <iostream>
#include <algorithm>

/*
This approach didn't work for some edge cases.
void rotateSubset(std::vector<int> &nums, int k, int shifts, int start) {
    int n = nums.size();
    int current = start;
    int temp = nums[current];
    
    for (int i = 0; i < shifts; i++) {
        int next = ((current - k) + n) % n;
        nums[current] = nums[next];
        current = next;
    }

    nums[current] = temp;
}

void rotate(std::vector<int> &nums, int k) {
    int n = nums.size();
    k %= n;

    if (k == 0)
        return;

    int subsets;
    int kInverse = n - k;

    if (n % k == 0)
        subsets = k;
    else if (n % 2 == 0 && k % 2 == 0)
        subsets = 2;
    else if (n % kInverse == 0)
        subsets = kInverse;
    else
        subsets = 1;

    int shifts = (n / subsets) - 1;

    for (int i = 0; i < subsets; i++)
        rotateSubset(nums, k, shifts, i);
}
*/

/**
 * Rotate an array of numbers k times.
 */
void rotate(std::vector<int> &nums, int k) {
    int n = nums.size();
    k %= n;

    if (k == 0)
        return;

    std::reverse(nums.begin(), nums.end());
    std::reverse(nums.begin(), nums.begin() + k);
    std::reverse(nums.end() + k, nums.end());
}

int main() {
    std::vector nums{1, 2, 3, 4, 5, 6, 7};

    rotate(nums, 3);

    for (int num: nums)
        std::cout << num << ',';
}