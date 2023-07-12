#include <vector>
#include <map>
#include <utility>
#include <algorithm>
#include <iterator>
#include <iostream>

/**
 * Find the enxt greater element of a list of numbers.
 */
std::vector<int> nextGreaterElement(std::vector<int> &nums1, std::vector<int> &nums2) {
    std::map<int, int> elements;
    std::vector<int> output;
    int n = nums2.size();

    for (int i = 0; i < n; i++)
        elements.insert({nums2[i], i});

    for (int query: nums1) {
        auto entry = elements.find(query);
        auto last = std::prev(elements.end());

        if (entry == last)
            output.push_back(-1);
        else {
            int i;

            for (i = entry->second; i < n; i++) {
                if (nums2[i] > entry->first)
                    break;
            }

            output.push_back(i == n ? -1 : nums2[i]);
        }
    }
    
    return output;
}

int main() {
    std::vector<int> nums1{2, 1, 3};
    std::vector<int> nums2{2, 3, 1};
    nextGreaterElement(nums1, nums2);
}