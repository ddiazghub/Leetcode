#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

std::string stoneGameIII(std::vector<int> &stoneValue) {
    int n = stoneValue.size();
    std::vector<int> cumulative(n + 3);
    cumulative[0] = stoneValue[0];

    for (int i = 1; i < n; i++)
        cumulative[i] = cumulative[i - 1] + stoneValue[i];

    if (cumulative[n - 1] < 0 && n == 3) {
        if (stoneValue[0] + stoneValue[1] > stoneValue[2])
            return "Alice";
        else if (stoneValue[0] + stoneValue[1] == stoneValue[2])
            return "Tie";
        else
            return "Bob";
    }

    cumulative[n] = cumulative[n - 1];
    cumulative[n + 1] = cumulative[n];
    cumulative[n + 2] = cumulative[n];

    int current = 0;
    int alice = 0;
    int bob = 0;
    bool aliceTurn = true;

    while (current < n) {
        int first = cumulative[current];
        int second = cumulative[current + 1];
        int third = cumulative[current + 2];
        int points;

        if (second > first) {
            if (third > second) {
                points = third;
                current += 3;
            } else {
                points = second;
                current += 2;
            }
        } else {
            if (third > first) {
                points = third;
                current += 3;
            } else {
                points = first;
                current++;
            }
        }

        if (aliceTurn)
            alice += points - bob;
        else
            bob += points - alice;

        aliceTurn = !aliceTurn;
    }


    if (alice == bob)
        return "Tie";

    if (alice > bob)
        return "Alice";

    return "Bob";
}

int main() {
    std::vector<int> nums{-1,-2,-3};
    std::cout << stoneGameIII(nums) << '\n';
}