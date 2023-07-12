#include <vector>
#include <unordered_set>

/**
 * Check if an array contains duplicate elements.
 */
bool containsDuplicate(std::vector<int> &nums) {
    std::unordered_set<int> found;

    for (int num: nums) {
        if (found.find(num) != found.end())
            return true;

        found.insert(num);
    }

    return false;
}