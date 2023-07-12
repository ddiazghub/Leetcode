#include <vector>
#include <iostream>
#include <algorithm>

/**
 * Find the triangle with the largest perimeter that can be built from a list of sides.
 */
int largestPerimeter(std::vector<int>& nums) {
    std::sort(nums.begin(), nums.end());

    for (int i = nums.size() - 1; i > 1; i--) {
        int a = nums[i], b = nums[i - 1], c = nums[i - 2];

        if (a + b > c && a + c > b && b + c > a)
            return a + b + c;
    }

    return 0;
}

int main() {

}