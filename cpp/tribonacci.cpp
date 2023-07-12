#include <array>

/**
 * Tribonacci series. Basically fibonacci but remembers a third value.
 */
int tribonacci(int n) {
    std::array<int, 3> previous{0, 1, 1};

    if (n < 3)
        return previous[n];

    for (int i = 3; i < n; i++) {
        int next = previous[0] + previous[1] + previous[2];
        previous[0] = previous[1];
        previous[1] = previous[2];
        previous[2] = next;
    }

    return previous[0] + previous[1] + previous[2];
}

int main() {

}