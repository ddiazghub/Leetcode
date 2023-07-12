#include <vector>
#include <unordered_map>
#include <set>
#include <utility>

/**
 * Return the top K most frequent elements in an array.
 */
std::vector<int> topKFrequent(std::vector<int> &nums, int k) {
    std::unordered_map<int, int> elements;

    for (int num: nums)
        elements[num]++;

    std::set<std::pair<int, int>> topFrequent;

    for (auto [element, frequency] : elements)
        topFrequent.insert(std::make_pair(frequency, element));

    std::vector<int> topKFrequent;
    auto end = std::next(topFrequent.rbegin(), k);

    for (auto iter = topFrequent.rbegin(); iter != end; iter++)
        topKFrequent.push_back(iter->second);

    return topKFrequent;
}

int main() {

}