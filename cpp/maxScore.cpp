#include <map>
#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <numeric>
#include <map>
#include <array>

constexpr int MAX_N = 1 << 14;
using MemEntry = std::pair<const std::pair<int, int>, int>;

int gcd(int number1, int number2, std::map<std::pair<int, int>, int> &memory) {
    if (number1 == 0)
        return number2;

    std::pair<int, int> pair{number1, number2};
    auto found = memory.find(pair);

    if (found != memory.end())
        return found->second;

    int value = gcd(number2 % number1, number1, memory);
    std::pair<int, int> inverted{number2, number1};
    memory.insert(MemEntry{pair, value});
    memory.insert(MemEntry{inverted, value});

    return value;
}

template <typename T>
void forEachPerm(std::vector<T> &elements, const std::function<void(std::vector<T> &)> &action) {
    int n = elements.size();
    std::vector<int> pointers(n + 1);
    std::iota(pointers.begin(), pointers.end(), 0);
    action(elements);
    int i = 1;

    while (i < n) {
        pointers[i]--;
        int j = i % 2 > 0 ? pointers[i] : 0;
        std::swap(elements[i], elements[j]);
        action(elements);
        i = 1;

        while (pointers[i] == 0) {
            pointers[i] = i;
            i++;
        }
    }
}

int maxScore(std::vector<int> nums, std::vector<std::pair<int, int>> pairs, std::map<std::pair<int, int>, int> &gcdMemory) {
    int n = nums.size();
    int max = 0;

    if (n == 2) {
        pairs.push_back(std::pair<int, int>{nums[0], nums[1]});

        forEachPerm(pairs, std::function<void(std::vector<std::pair<int, int>> &)>{ [&gcdMemory, &max](std::vector<std::pair<int, int>> &pairsPerm) {
            int score = 0;

            for (unsigned int i = 0; i < pairsPerm.size(); i++) {
                auto &pair = pairsPerm[i];
                score += (i + 1) * gcd(pair.first, pair.second, gcdMemory);
            }

            max = std::max(max, score);
        } });
    } else {
        for (int i = 3; i < n; i++) {
            std::vector<int> subset{nums[2], nums[i]};
            std::vector<std::pair<int, int>> subpairs(pairs);
            
            for (int j = 3; j < n; j++) {
                if (i != j)
                    subset.push_back(nums[j]);
            }

            subpairs.push_back(std::pair<int, int>{nums[0], nums[1]});
            max = std::max(max, maxScore(subset, subpairs, gcdMemory));
        }
    }

    return max;
}

int maxScore2(std::vector<int> &nums) {
    std::map<std::pair<int, int>, int> gcdMemory;
    int n = nums.size();
    int max = 0;

    for (int i = 1; i < n; i++) {
        std::vector<int> subset{nums[0], nums[i]};

        for (int j = 1; j < n; j++) {
            if (i != j)
                subset.push_back(nums[j]);
        }

        max = std::max(max, maxScore(subset, std::vector<std::pair<int, int>>{}, gcdMemory));
    }

    return max;
}

int maxScore(std::vector<int> nums, int bitmask, int current, std::map<std::pair<int, int>, int> &gcdMemory, std::array<int, MAX_N> &scoreMemory) {
    if (bitmask == 0)
        return 0;
    
    if (scoreMemory[bitmask] > 0)
        return scoreMemory[bitmask];

    int n = nums.size();
    int max = 0;

    for (int i = 0; i < n - 1; i++) {
        int iMask = (1 << i);

        if ((bitmask & iMask) > 0) {
            for (int j = i + 1; j < n; j++) {
                int jMask = (1 << j);

                if ((bitmask & jMask) > 0) {
                    int newMask = bitmask & ~iMask & ~jMask;
                    int score = current * gcd(nums[i], nums[j], gcdMemory) + maxScore(nums, newMask, current + 1, gcdMemory, scoreMemory);
                    max = std::max(max, score);
                }
            }
        }
    }

    scoreMemory[bitmask] = max;

    return max;
}

int maxScore(std::vector<int> &nums) {
    std::map<std::pair<int, int>, int> gcdMemory;
    std::array<int, MAX_N> scoreMemory;
    int initialBitmask = (1 << (nums.size())) - 1;

    return maxScore(nums, initialBitmask, 1, gcdMemory, scoreMemory);
}

int main() {
    std::vector<int> nums{984916, 312350, 779975, 165893, 436389, 592384, 264617, 136726, 8893, 587955, 921403, 891842};
    std::cout << maxScore(nums) << '\n';
}