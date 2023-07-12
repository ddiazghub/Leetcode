#include <vector>
#include <string>

/**
 * It's just FizzBuzz.
 */
std::vector<std::string> fizzBuzz(int n) {
    std::vector<std::string> answer;

    for (int i = 1; i <= n; i++) {
        bool fizz = i % 3 == 0;
        bool buzz = i % 5 == 0;
        std::string ans;

        if (fizz)
            ans += "Fizz";
        
        if (buzz)
            ans += "Buzz";
        
        if (ans.size() == 0)
            ans += std::to_string(i);

        answer.push_back(ans);
    }

    return answer;
}

int main() {

}