#include <vector>

/**
 * Remove all ocurrences of a value from a vector. 
 */
int removeElement(std::vector<int> &nums, int val) {
    int n = 0;

    for (unsigned int i = 0; i < nums.size(); i++) {
        if (nums[i] != val) {
            nums[n] = nums[i];
            n++;
        }
    }

    return n;
}

int main() {

}