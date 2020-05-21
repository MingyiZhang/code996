from typing import List


def find_content_children(g: List[int], s: List[int]) -> int:
    g.sort()
    s.sort()
    i = len(g) - 1  # g
    j = len(s) - 1  # s
    ans = 0
    while i >= 0 and j >= 0:
        if g[i] <= s[j]:
            j -= 1
            ans += 1
        i -= 1
    return ans


if __name__ == '__main__':
    assert(1 == find_content_children([1, 2, 3], [1, 1]))
    assert(2 == find_content_children([1, 2], [1, 2, 3]))
