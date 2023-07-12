#include <string_view>
#include <string>
#include <iostream>

/**
 * Find a needle in a haystack, just find a substring in a bigger string.
 */
int strStr(std::string haystack, std::string needle) {
    std::string_view hs{haystack};
    std::string_view need{needle};

    int n = haystack.size();
    int m = needle.size();

    for (int i = 0; i < n - m + 1; i++) {
        if (hs.substr(i, m) == need)
            return i;
    }

    return -1;
}

int main() {
    strStr("mississippi", "issip");
}