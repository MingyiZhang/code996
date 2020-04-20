def is_subsequence(s: str, t: str) -> bool:
    # i = j = 0
    # while i < len(s) and j < len(t):
    #     if s[i] == t[j]:
    #         i += 1
    #     j += 1
    # return i == len(s)

    # use build-in function is faster
    idx = -1
    for c in s:
        idx = t.find(c, idx + 1)
        if idx == -1:
            return False
    return True


if __name__ == '__main__':
    assert(is_subsequence("abc", "ahbgdc"))
    assert(not is_subsequence("axc", "ahbgdc"))
