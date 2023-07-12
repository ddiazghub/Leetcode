#include <string>
#include <unordered_map>

bool isAnagram(std::string s, std::string t) {
    std::unordered_map<char, int> chars;

    for (char ch : s)
        chars[ch]++;

    for (char ch : t) {
        auto entry = chars.find(ch);

        if (entry == chars.end())
            return false;

        entry->second--;

        if (entry->second == 0)
            chars.erase(ch);
    }

    return chars.size() == 0;
}

int main() {
    
}