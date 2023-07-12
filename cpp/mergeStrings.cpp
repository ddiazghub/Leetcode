#include <string>
#include <array>
#include <algorithm>

/**
 * Merge 2 strings by alternating chars.
 */
std::string mergeAlternately(std::string word1, std::string word2) {
    int n = word1.size(), m = word2.size();
    std::string merged;
    merged.resize(n + m);
    bool second = false;
    int current = 0;
    int outIndex = 0;

    while (current < n && current < m) {
        if (second) {
            merged[outIndex] = word2[current];
            current++;
        } else {
            merged[outIndex] = word1[current];
        }

        outIndex++;
        second = !second;
    }

    if (current == n)
        std::copy(word2.cbegin() + current, word2.cend(), merged.begin() + outIndex);
    else
        std::copy(word1.cbegin() + current, word1.cend(), merged.begin() + outIndex);

    return merged;
}

int main() {

}