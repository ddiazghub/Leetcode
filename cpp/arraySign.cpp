#include <vector>

constexpr int SIGN_BITMASK = 1 << 31;

/**
 * Find the sign of the product of an array.
 */
int arraySign(std::vector<int>& nums) {
    int sign = 1;

    for (int num: nums) {
        if (num == 0)
            return 0;

        sign ^= num;
    }

    return sign < 0 ? -1 : 1;
}

int main() {

}