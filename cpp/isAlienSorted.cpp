#include <vector>
#include <unordered_map>
#include <string>
#include <algorithm>

constexpr int ALPHABET_SIZE = 26;

bool isAlienSorted(std::vector<std::string> &words, std::string order) {
    std::unordered_map<char, int> charIndexes;

    for (int i = 0; i < ALPHABET_SIZE; i++)
        charIndexes.insert({order[i], i});

    int numWords = words.size();

    for (int i = 1; i < numWords; i++) {
        int shortestLen = std::min(words[i - 1].size(), words[i].size());
        bool less = false;

        for (int j = 0; j < shortestLen; j++) {
            int idx1 = charIndexes.find(words[i - 1][j])->second;
            int idx2 = charIndexes.find(words[i][j])->second;
            
            if (idx1 < idx2) {
                less = true;
                break;
            } else if (idx1 > idx2) {
                return false;
            }
        }

        if (!less && shortestLen < static_cast<int>(words[i - 1].size()))
            return false;
    }

    return true;
}

int main() {

}