def length(slice: tuple[int, int]) -> int:
    return slice[1] - slice[0] + 1

def longest_palindrome(self, s: str) -> str:
    n = len(s)
    palindromes: list[list[bool]] = [[False] * n] * n
    longest = (0, 0)

    for i in range(n):
        palindromes[i][i] = True

    for slice_len in range(2, n):
        """
        pal[start][end] is palindrome if pal[start + 1][end - 1] is palindrome and s[end] == s[start]
        """
        start = 0
        end = slice_len - 1

        while end < n:
            inner = palindromes[start + 1][end - 1]
            palindromes[start][end] = inner and s[start] == s[end]

            if palindromes[start][end]:
                longest = max(length(longest), length)

    return ""
