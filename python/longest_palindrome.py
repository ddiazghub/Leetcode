def longest_palindrome(s: str) -> str:
    n = len(s)
    longest = (0, 0)
    longest_len = 1
    palindromes: list[list[bool]] = [[False for i in range(n)] for j in range(n)]

    for i in range(n):
        palindromes[i][i] = True

    for length in range(2, n + 1):
        start = 0
        end = length - 1

        while end < n:
            inner = palindromes[start + 1][end - 1] if end > start + 1 else True
            palindromes[start][end] = inner and s[start] == s[end]

            if palindromes[start][end]:
                longest_len = max(length, longest_len)

                if longest_len == length:
                    longest = (start, end)
            
            start += 1
            end += 1

    return s[longest[0]:longest[1] + 1]


if __name__ == "__main__":
    print(longest_palindrome("bb"))
