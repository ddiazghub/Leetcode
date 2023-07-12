#include <string>
#include <vector>
#include <iostream>

/**
 * Find if it is possible to make both strings equal by performing at most one string swap on exactly one of the strings.
 */
bool areAlmostEqual(std::string s1, std::string s2) {
    int n = s1.size();
    std::vector<int> diff;

    for (int i = 0; i < n; i++) {
        if (s1[i] != s2[i]) {
            diff.push_back(i);

            if (diff.size() > 2)
                return false;
        }
    }

    return diff.size() == 0 || (diff.size() == 2 && s1[diff[0]] == s2[diff[1]] && s2[diff[0]] == s1[diff[1]]);
}

int main() {
    std::cout << areAlmostEqual("bank", "kanb") << '\n';
}