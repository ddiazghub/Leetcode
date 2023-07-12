#include <vector>
#include <numeric>
#include <algorithm>

/**
 * Given an array of positive integers arr, return the sum of all possible odd-length subarrays of arr.
 * Brute force approach.
 */
int sumOddLengthSubarrays(std::vector<int> &array) {
    int size = array.size() + 1;
    int sum = 0;

    for (int subLen = 1; subLen < size; subLen += 2) {
        for (int i = 0; i < size - subLen; i++) {
            auto start = array.cbegin() + i;
            sum += std::accumulate(start, start + subLen, 0);
        }
    }

    return sum;
}

int main() {
    std::vector<int> nums{10, 11, 12};
    sumOddLengthSubarrays(nums);
}