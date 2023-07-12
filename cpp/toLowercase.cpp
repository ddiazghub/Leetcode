#include <string>
#include <algorithm>
#include <cstring>

/**
 * Convert each char in a string to lowercase.
 */
std::string toLowerCase(std::string s) {
    for (char &ch : s)
        ch = static_cast<char>(std::tolower(ch));

    return s;
}

int main() {

}