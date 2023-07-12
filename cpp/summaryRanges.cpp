#include <vector>
#include <string>
#include <utility>

std::vector<std::string> summaryRanges(std::vector<int> &nums) {
    int size = nums.size();

    if (size == 0)
        return {};
    
    std::pair<int, int> first{nums[0], nums[0]};
    std::vector<std::pair<int, int>> ranges{first};
    std::vector<std::string> output;

    for (int i = 1; i < size; i++) {
        auto &last = ranges.back();
        int num = nums[i];

        if (last.second + 1 == num)
            last.second = num;
        else
            ranges.push_back(std::make_pair(num, num));
    }

    for (auto [start, end] : ranges) {
        if (start == end)
            output.push_back(std::to_string(start));
        else
            output.push_back(std::to_string(start) + "->" + std::to_string(end));
    }

    return output;
}

int main() {

}