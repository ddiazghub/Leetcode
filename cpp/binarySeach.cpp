#include <vector>

/**
 * It's binary search, no need to explain anything.
 */
int search(std::vector<int>& nums, int target) {
    int start = 0;
    int end = nums.size();

    while (start < end) {
        int mid = start + (end - start) / 2;

        if (nums[mid] < target)
            start = mid + 1;
        else if (nums[mid] > target)
            end = mid;
        else
            return mid;
    }

    return -1;
}

int main() {}