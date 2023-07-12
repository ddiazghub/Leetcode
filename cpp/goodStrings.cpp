#include <iostream>
#include <vector>
#include <algorithm>

const int MOD = 1000000007;

/**
 * Passing a struct reference to a function is much better than passing a mess of 10 different parameters.
 * The only purpose of this struct is to reduce the number of arguments passed to the recursive approach.
 */
struct Constraints {
    int low;
    int high;
    int zero;
    int one;
    Constraints(int low, int high, int zero, int one) : low(low), high(high), zero(zero), one(one) {}
};

/**
 * Count number of good strings in range that can be generated with the given constraints.
 * Recursive approach using memoization.
 */
int countGoodStrings(Constraints &constraints, int current, std::vector<int> &memory) {
    if (memory[current] == -1) {
        int zeroCount = countGoodStrings(constraints, current + constraints.zero, memory);
        int oneCount = countGoodStrings(constraints, current + constraints.one, memory);
        memory[current] = (zeroCount + oneCount + (current >= constraints.low ? 1 : 0)) % MOD;
    }

    return memory[current];
}

/**
 * Count number of good strings in range that can be generated with the given constraints.
 * Tabulated approach.
 */
int countGoodStrings(int low, int high, int zero, int one) {
    std::vector memory(high + std::max(zero, one) + 1, -1);
    std::fill(memory.begin() + high, memory.end(), 0);
    memory[high] = 1;
    
    /*
    To call recursive approach:
    Constraints constraints(low, high, zero, one)

    return countGoodStrings(constraints, 0, memory);
    */

    for (int i = high - 1; i > -1; i--)
        memory[i] = (memory[i + zero] + memory[i + one] + (i >= low ? 1 : 0)) % MOD;

    return memory[0];
}

int main() {
    std::cout << countGoodStrings(3, 3, 1, 1) << '\n';
    std::cout << countGoodStrings(200, 200, 10, 1) << '\n';
}