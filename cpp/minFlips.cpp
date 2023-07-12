#include <iostream>

/**
 * Test a single bit in an int.
 */
inline bool test(int number, int bit) {
    return static_cast<bool>(number & (1 << bit));
}

int minFlips(int a, int b, int c) {
    int count = 0;

    for (int i = 0; i < 32; i++) {
        bool bitA = test(a, i);
        bool bitB = test(b, i);
        bool bitC = test(c, i);

        if (bitC) {
            if (!(bitA || bitB))
                count += 1;
        } else {
            count += bitA + bitB;
        }
    }

    return count;
}

int main() {
    std::cout << minFlips(2, 6, 5) << '\n';
}