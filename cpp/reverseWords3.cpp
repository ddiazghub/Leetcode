#include <string>

/**
 * Find the index of the start of the next word in the string from a starting offset.
 */
int seekNextWord(std::string &str, int start) {
    int n = str.size();
    int i = start;

    while (i < n && str[i] == ' ')
        i++;

    return i;
}

/**
 * Find the index of the next whitespace in the string from a starting offset.
 */
int seekWhitespace(std::string &str, int start) {
    int n = str.size();
    int i = start;

    while (i < n && str[i] != ' ')
        i++;

    return i;
}

/**
 * Reverse each word in a string.
 */
std::string reverseWords(std::string s) {
    int right = seekNextWord(s, 0);
    int left = right;
    int n = s.size();

    while (left < n) {
        int end = seekWhitespace(s, right);
        right = end - 1;

        while (left < right) {
            std::swap(s[left], s[right]);
            left++;
            right--;
        }

        right = seekNextWord(s, end);
        left = right;
    }

    return s;
}