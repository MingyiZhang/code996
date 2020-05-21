def is_palindrome(s: str, left: int, right: int) -> bool:
    while left < right:
        if s[left] != s[right]:
            return False
        left += 1
        right -= 1
    return True


def valid_palindrome_ii(s: str) -> bool:
    left = 0
    right = len(s) - 1
    while left < right:
        if s[left] != s[right]:
            return is_palindrome(s, left + 1, right) or is_palindrome(s, left, right - 1)
        left += 1
        right -= 1
    return True


if __name__ == '__main__':
    assert (valid_palindrome_ii("abcba"))
    assert (valid_palindrome_ii("abcbba"))
    assert (not valid_palindrome_ii("abcbbda"))
