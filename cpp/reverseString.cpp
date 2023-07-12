#include <vector>

/**
 * Reverses a "string".
 */
void reverseString(std::vector<char> &s) {
    int last = s.size() - 1;
    int half = s.size() / 2;

    for (int i = 0; i < half; i++)
        std::swap(s[i], s[last - i]);
}

int main() {

}