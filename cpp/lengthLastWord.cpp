#include <string>
#include <iostream>

/**
 * Find the length of the last word in a string.
 */
int lengthOfLastWord(std::string s) {
    int i = s.size() - 1;

    while (i > -1 && s[i] == ' ')
        i--;
    
    int length = 0;

    while (length <= i && s[i - length] != ' ')
        length++;

    return length;
}

int main() {
    std::cout << lengthOfLastWord("a") << '\n';
}