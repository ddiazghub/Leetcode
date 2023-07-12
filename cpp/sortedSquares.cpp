#include <vector>
#include <limits>
#include <iostream>

/**
 * Return the sorted squares of a list of sorted numbers
 */
std::vector<int> sortedSquares(std::vector<int> &nums) {
    // Initialize output vector.
    std::vector<int> output(nums.size() + 1, 0);

    // Set last value as integer max so end pointer never causes an out of bounds error.
    output[nums.size()] = std::numeric_limits<int>::max();

    // Initialize start and end pointers.
    int start = 0;
    int end = nums.size();

    for (int num: nums) {
        int square = num * num;

        // Number is negative, temporarily place the square at the end of the vector while we figure out it's actual position.
        if (num < 0) {
            end--;
            output[end] = square;
        } else {
            // Number is positive, find if there are negative squares which have to be placed before it and place them.
            while (square > output[end]) {
                output[start] = output[end];
                end++;
                start++;
            }

            // Place the number.
            output[start] = square;
            start++;
        }
    }

    // Remove last value before returning result.
    output.pop_back();

    return output;
}

int main() {
    std::vector<int> nums{-4, -1, 0, 3, 10};
    std::vector<int> squares = sortedSquares(nums);
    
    for (int square: squares)
        std::cout << square << ',';
}