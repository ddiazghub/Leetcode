#include <vector>
#include <string>
#include <cctype>
#include <utility>

/**
 * Permutate the next letter in a string, storing the permutation in the permutations vector if the string has been completely permutated.
 */
void permutate(std::vector<std::string> &permutations, std::string &s, std::string base) {
    size_t i = base.size();

    if (i == s.size())
        return permutations.push_back(base);

    if (std::isalpha(s[i])) {
        std::string lower = std::move(base);
        std::string upper = lower + static_cast<char>(std::toupper(s[i]));
        lower += static_cast<char>(std::tolower(s[i]));

        permutate(permutations, s, lower);
        return permutate(permutations, s, upper);
    }

    return permutate(permutations, s, base + s[i]);
}

std::vector<std::string> letterCasePermutation(std::string s) {
    std::vector<std::string> permutations;
    permutate(permutations, s, "");

    return permutations;
}

int main() {

}
