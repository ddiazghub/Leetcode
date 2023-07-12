#include <string>
#include <unordered_map>
#include <algorithm>
#include <array>

inline int indexOf(char ch) {
    return static_cast<int>(ch - 'a');
}

/**
 * Given two strings s1 and s2, return true if s2 contains a permutation of s1, or false otherwise.
 */
bool checkInclusion(std::string s1, std::string s2) {
    int size2 = s2.size();
    int size1 = s1.size();
    
    if (size2 < size1)
        return false;

    std::array<int, 26> charCounts1{};
    std::array<int, 26> charCounts2{};

    for (char ch: s1)
        charCounts1[indexOf(ch)]++;

    int matching = 0;
    int i;

    for (i = 0; i < size1; i++) {
        int &count = charCounts2[indexOf(s2[i])];

        if (count < charCounts1[indexOf(s2[i])])
            matching++;

        count++;
    }

    if (matching == size1)
        return true;
    
    for (; i < size2; i++) {
        int &old = charCounts2[indexOf(s2[i - size1])];

        if (old <= charCounts1[indexOf(s2[i - size1])])
            matching--;

        old--;
        int &count = charCounts2[indexOf(s2[i])];

        if (count < charCounts1[indexOf(s2[i])])
            matching++;

        count++;

        if (matching == size1)
            return true;
    }

    return false;
}

int main() {
    checkInclusion("adc", "dcda");
}