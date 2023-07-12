#include <iostream>

/**
 * Calculates x raised to the power n (i.e., xn).
 */
double myPow2(double x, unsigned int n) {
    if (n == 0)
        return 1.0;

    double pow = myPow(x, n / 2);

    if (n % 2 == 0)
        return pow * pow;
    else
        return x * pow * pow;
}

/**
 * Calculates x raised to the power n (i.e., xn).
 */
double myPow(double x, int n) {
    if (n == 0)
        return 1.0;

    if (n < 0)
        return myPow2(1 / x, -static_cast<long long>(n));

    return myPow2(x, n);
}

int main() {
    std::cout << myPow(2.1, 3) << '\n';
}