#include <string>
#include <unordered_map>
#include <utility>
#include <algorithm>
#include <limits>

/**
 * Find first non-repeating character in string.
 */
int firstUniqChar(std::string s) {
    std::unordered_map<char, std::pair<int, int>> chars;
    int size = s.size();

    for (int i = 0; i < size; i++) {
        auto entry = chars.find(s[i]);

        if (entry == chars.end())
            chars.insert(std::make_pair(s[i], std::make_pair(i, 1)));
        else
            entry->second.second++;
    }

    int min = std::numeric_limits<int>::max();
    
    for (auto &entry : chars) {
        if (entry.second.second == 1)
            min = std::min(min, entry.second.first);
    }

    return min == std::numeric_limits<int>::max() ? -1 : min;
}

int main() {

}