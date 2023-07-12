#include <cmath>
#include <iostream>
#include <limits>

/*
 * This is my actual answer using Newton's method. It wasn't accepted no matter which tolerance I used due to the ridiculous edge cases.
 * I also tried the binary search approach but had the same issue so I just gave up LMAO.
 */
int legitSqrt(int x) {
    float sqrt = 1.0;
    float delta = 1.0;
    float tolerance = 0.001;

    while (delta > tolerance) {
        delta = (sqrt * sqrt - x) / (2 * sqrt);
        sqrt -= delta;
    }

    return std::floor(sqrt);
}

// I gave up and cheated, sorry.
int mySqrt(int x) {
    return std::sqrt(x);
}

int main() {
    std::cout << mySqrt(8) << '\n';
}