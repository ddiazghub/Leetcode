#include <vector>
#include <algorithm>
#include <array>

/**
 * You are given an integer array cost where cost[i] is the cost of ith step on a staircase.
 * Once you pay the cost, you can either climb one or two steps.
 * Return the minimum cost to reach the top of the floor.
 */
int minCostClimbingStairs(std::vector<int> &cost) {
    int n = cost.size();
    std::array<int, 2> previous{0, 0};

    for (int i = n - 1; i > -1; i--) {
        int current = cost[i] + std::min(previous[0], previous[1]);
        previous[0] = previous[1];
        previous[1] = current;
    }

    return std::min(previous[0], previous[1]);
}

int main() {

}