#include <vector>
#include <unordered_map>

/**
 * Find the intersection of 2 arrays.
 */
std::vector<int> intersect(std::vector<int> &nums1, std::vector<int> &nums2) {
    std::unordered_map<int, int> elements;
    std::vector<int> intersect;

    for (int num: nums1)
        elements[num]++;

    for (int num: nums2) {
        auto entry = elements.find(num);

        if (entry != elements.end() && entry->second > 0) {
            intersect.push_back(num);
            entry->second--;
        }
    }

    return intersect;
}

int main() {

}