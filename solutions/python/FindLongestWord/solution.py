from typing import List


def is_sub(w: str, s: str) -> bool:
    found = -1
    for i, c in enumerate(w):
        found = s.find(c, found + 1)
        if found == -1 or len(s) - found < len(w) - i:
            return False
    return True


def find_longest_word(s: str, d: List[str]) -> str:
    d.sort(key=lambda x: (1 / (len(x) + 1), x))
    for w in d:
        if is_sub(w, s):
            return w
    return ''


if __name__ == '__main__':
    s = 'abpcplea'
    d1 = ['ale', 'apple', 'monkey', 'plea']
    ret = find_longest_word(s, d1)
    assert ('apple' == ret)
