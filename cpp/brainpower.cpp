#include <vector>
#include <algorithm>
#include <iostream>

/**
 * Find the most points achievable by answering a list of questions.
 * Each questions grants an amount of points, however it causes you to skip the next questions due to brain fatigue :(.
 */
long long mostPoints(std::vector<std::vector<int>> &questions) {
    int n = questions.size();
    std::vector<long long> memory(n + 1);

    for (int i = n - 1; i > -1; i--) {
        std::vector<int> &question = questions[i];
        int skip = question[1] + i + 1;
        memory[i] = std::max(memory[i + 1], question[0] + (skip < n ? memory[skip] : 0));
    }

    return memory[0];
}

int main() {
    std::vector<std::vector<int>> nums{{3, 2}, {4, 3}, {4, 4}, {2, 5}};
    std::cout << mostPoints(nums) << '\n';
}