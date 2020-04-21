from typing import List


def next_greatest_letter(letters: List[str], target: str) -> str:
    n = len(letters)
    left, right = 0, n - 1
    while left <= right:
        mid = (left + right) // 2
        if letters[mid] <= target:
            left = mid + 1
        else:
            right = mid - 1
    return letters[left] if left < n else letters[0]


if __name__ == '__main__':
    letters = ['c', 'f', 'j']
    assert ('c' == next_greatest_letter(letters, 'a'))
    assert ('f' == next_greatest_letter(letters, 'c'))
    assert ('f' == next_greatest_letter(letters, 'd'))
    assert ('j' == next_greatest_letter(letters, 'g'))
    assert ('c' == next_greatest_letter(letters, 'j'))
    assert ('c' == next_greatest_letter(letters, 'k'))
