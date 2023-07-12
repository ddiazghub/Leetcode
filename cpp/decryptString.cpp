#include <string>
#include <vector>

constexpr int BASE = static_cast<int>('a') - 1;

std::string freqAlphabets(std::string s) {
    std::string chars;
    std::string output;

    for (char ch : s) {
        if (chars.size() == 2) {
            int value;

            if (ch == '#') {
                value = std::stoi(chars);
                chars = "";
            } else {
                value = (chars[0] - '0');
                chars.erase(0, 1);
            }

            output.push_back(static_cast<char>(value + BASE));
        }

        if (ch != '#')
            chars.push_back(ch);
    }

    switch (chars.size()) {
        case 1:
            output.push_back(static_cast<char>((chars[0] - '0') + BASE));
            break;
        case 2:
            output.push_back(static_cast<char>((chars[0] - '0') + BASE));
            output.push_back(static_cast<char>((chars[1] - '0') + BASE));
        default:
            break;
    }   

    return output;
}

int main() {
    std::string str{"10#11#12"};
    freqAlphabets(str);
}