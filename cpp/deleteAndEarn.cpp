#include <vector>
#include <map>
#include <algorithm>
#include <limits>
#include <iostream>
#include <utility>

int deleteAndEarn(std::map<int, int>::iterator start, std::map<int, int>::iterator end, int lastTaken) {
    if (start == end)
        return 0;
    
    auto next = std::next(start);
    int skipping = deleteAndEarn(next, end, lastTaken);

    if (next->first < lastTaken + 2)
        return skipping;

    int taking = next->first * next->second + deleteAndEarn(next, end, next->first);

    return std::max(taking, skipping);
}

int deleteAndEarn(std::vector<int> &nums) {
    std::map<int, int> elements{
        {std::numeric_limits<int>::max(), 0}
    };

    for (auto &num: nums)
        elements[num]++;

    int n = elements.size();
    auto current = std::next(elements.rbegin());
    std::vector<std::pair<int, int>> maxPoints(n + 2);

    for (int i = n - 1; i > -1; i--) {
        auto [last, skipping] = maxPoints[i + 1];
        auto [value, count] = *current;
        int taking = value * count + (last > value + 1 ? skipping : maxPoints[i + 2].second);
        maxPoints[i] = std::make_pair(value, std::max(taking, skipping));
        current++;
    }

    return maxPoints[0].second;
}

int main() {
    std::vector<int> nums{2,2,3,3,3,4};
    std::cout << deleteAndEarn(nums) << '\n';
}