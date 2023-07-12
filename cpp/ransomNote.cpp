#include <string>
#include <unordered_map>

/**
 * Given two strings ransomNote and magazine, return true if ransomNote can be constructed by using the letters from magazine and false otherwise.
 */
bool canConstruct(std::string ransomNote, std::string magazine) {
    std::unordered_map<char, int> characterCounts;
    
    for (char ch: magazine)
        characterCounts[ch]++;
    
    for (char ch: ransomNote) {
        auto entry = characterCounts.find(ch);

        if (entry == characterCounts.end() || entry->second < 1)
            return false;

        entry->second--;
    }

    return true;
}

int main() {

}