#include <iostream>

/**
 * Find if a number is a palindrome.
 */
bool isPalindrome(int x) {
    if (x < 0 || (x > 0 && x % 10 == 0))
        return false;
    
    int reversed = 0;

    while (x > reversed) {
        reversed = reversed * 10 + x % 10;
        x /= 10;
    }

    return reversed == x || reversed / 10 == x;
}

int main() {
    std::cout << isPalindrome(1023201) << '\n';
    std::cout << isPalindrome(101) << '\n';
    std::cout << isPalindrome(102201) << '\n';
    std::cout << isPalindrome(10) << '\n';
    std::cout << isPalindrome(98450) << '\n';
}