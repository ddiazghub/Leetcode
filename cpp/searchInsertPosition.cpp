#include <vector>

/**
 * Search the insertion position of a value in a sorted vector.
 * This is just binary search again.
*/
int searchInsert(std::vector<int>& nums, int target) {
    int start = 0;
    int end = nums.size();
    
    while (start != end) {
        int mid = start + (end - start) / 2;

        if (nums[mid] < target)
            start = mid + 1;
        else if (nums[mid] > target)
            end = mid;
        else
            return mid;
    }

    return start;
}

int main() {}