#include <vector>
#include <utility>
#include <algorithm>

int count1Bits(int number) {
    int count = 0;

    for (int i = 0; i < 32; i++) {
        if (number & (1 << i))
            count++;
    }

    return count;
}

std::vector<int> sortByBits(std::vector<int> &arr) {
    std::vector<std::pair<int, int>> weights;

    for (int num : arr)
        weights.push_back(std::make_pair(count1Bits(num), num));

    std::sort(weights.begin(), weights.end());
    std::vector<int> output;

    for (auto [_, num] : weights)
        output.push_back(num);

    return output;
}

int main() {
    
}