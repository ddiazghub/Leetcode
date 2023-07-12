#include <cstdint>

/**
 * Reverse the bits of a number.
 */
uint32_t reverseBits(uint32_t n) {
    uint32_t output = 0;

    for (int i = 0; i < 16; i++) {
        output |= (n & (1 << i)) << (31 - 2 * i);
        output |= (n & (0x80000000 >> i)) >> (31 - 2 * i);
    }

    return output;
}

int main() {

}