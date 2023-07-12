#include <unordered_set>

/**
 * Finds the sum of the squares of the digits of a number.
 */
int sumOfSquareDigits(int n) {
    int sum = 0;

    while (n > 0) {
        int digit = n % 10;
        sum += digit * digit;
        n /= 10;
    }

    return sum;
}

/**
 * Finds if a number is a happy number, that is, that by repeatedly replacing it by the sum of the squares of it's digits we can reach the number 1.
 */
bool isHappy(int n) {
    std::unordered_set<int> found{1};
    n = sumOfSquareDigits(n);

    while (found.find(n) == found.end()) {
        found.insert(n);
        n = sumOfSquareDigits(n);
    }

    return n == 1;
}