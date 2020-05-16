from typing import List, Set

KEYS = {
    '2': 'abc',
    '3': 'def',
    '4': 'ghi',
    '5': 'jkl',
    '6': 'mno',
    '7': 'pqrs',
    '8': 'tuv',
    '9': 'wxyz'
}


def do_combinations(prefix: str, digits: str, combinations: Set[str]) -> None:
    if len(prefix) == len(digits):
        combinations.add(prefix)
        return
    d = digits[len(prefix)]
    for c in KEYS[d]:
        prefix += c
        do_combinations(prefix, digits, combinations)
        prefix = prefix[:-1]


def letter_combinations(digits: str) -> List[str]:
    if len(digits) == 0:
        return []
    ret = set()
    do_combinations('', digits, ret)
    return list(ret)
