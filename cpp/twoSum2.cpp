#include <vector>

/**
 * Find the indexes (1-indexed yuck) of the 2 elements in the array that add up to target.
 */
std::vector<int> twoSum(std::vector<int> &numbers, int target) {
    int n = numbers.size();
    int start = 0;
    int end = n - 1;

    while (start < end) {
        int sum = numbers[start] + numbers[end];

        if (sum == target)
            break;
        else if (sum < target)
            start++;
        else
            end--;
    }

    return {start + 1, end + 1};
}

int main() {

}