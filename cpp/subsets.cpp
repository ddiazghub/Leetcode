#include <vector>
#include <algorithm>
#include <set>
#include <numeric>
#include <iostream>

/**
 * Generate all posible subsets of the given size. Insert them in the output set of sets.
 */
inline void setsOfSize(std::vector<int> &nums, int size, std::set<std::vector<int>> &output) {
    std::vector<int> indexes(size);
    std::iota(indexes.begin(), indexes.end(), 0);
    int n = nums.size();

    while (true) {
        std::vector<int> set;

        for (int index: indexes)
            set.push_back(nums[index]);

        output.insert(set);
        int inv = 0;
        int i = size - 1;
        indexes[i]++;

        while (i > 0 && indexes[i] == n - inv) {
            inv++;
            i--;
            indexes[i]++;
        }

        if (indexes[0] == n - size + 1)
            break;

        for (i = i + 1; i < size; i++)
            indexes[i] = indexes[i - 1] + 1;
    }
}

/**
 * Generate all posible subsets of ANY size for a vector of numbers.
 */
std::vector<std::vector<int>> subsets(std::vector<int> &nums) {
    std::sort(nums.begin(), nums.end());
    std::set<std::vector<int>> sets{{}};

    for (unsigned int setSize = 1; setSize <= nums.size(); setSize++) {
        setsOfSize(nums, setSize, sets);
    }

    return std::vector<std::vector<int>>(sets.begin(), sets.end());
}

int main() {
    std::vector nums{1, 2, 3};
    auto sets = subsets(nums);
    
    for (auto &set: sets) {
        std::cout << '[';

        for (int num: set)
            std::cout << num << ',';

        std::cout << "]\n";
    }
}