#include <string>
#include <unordered_map>
#include <algorithm>

/**
 * Given a string s, find the length of the longest substring without repeating characters.
 */
int lengthOfLongestSubstring(std::string s) {
    std::unordered_map<char, int> found;
    int max = 0;
    int start = 0;
    int size = s.size();

    for (int i = 0; i < size; i++) {
        char ch = s[i];
        auto entry = found.find(ch);

        if (entry != found.end()) {
            for (int j = start; j < entry->second; j++)
                found.erase(s[j]);
            
            max = std::max(max, i - start);
            start = entry->second + 1;
            found.erase(ch);
        }

        found.insert({ch, i});
    }

    return std::max(max, size - start);
}

int main() {
    lengthOfLongestSubstring("abcabcbb");
}