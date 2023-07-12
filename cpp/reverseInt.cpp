#include <limits>
#include <iostream>

int reverse(int x) {
    if (x == 0)
        return 0;

    int reversed = 0;
    int max = std::numeric_limits<int>::max();
    int min = std::numeric_limits<int>::min();

    if (x < 0) {
        while (x < 0) {
            int digit = x % 10;

            if (reversed < -1) {
                if (min / reversed < 10 || 10 * reversed - digit < min)
                    return 0;
            }
            
            reversed = reversed * 10 + digit;
            x /= 10;
        }
    } else {
        while (x > 0) {
            int digit = x % 10;

            if (reversed > 0) {
                if (max / reversed < 10 || max - 10 * reversed < digit)
                    return 0;
            }
            
            reversed = reversed * 10 + digit;
            x /= 10;
        }
    }

    return reversed;
}

int main() {
    std::cout << reverse(-123) << '\n';
}