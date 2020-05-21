from typing import List


def two_sum(numbers: List[int], target: int) -> List[int]:
    i: int = 0
    j: int = len(numbers) - 1
    while i < j:
        s = numbers[i] + numbers[j]
        if s == target:
            return [i + 1, j + 1]
        elif s < target:
            i += 1
        else:  # sum > target
            j -= 1
    return []


if __name__ == '__main__':
    assert(two_sum([2, 7, 9, 11], 9) == [1, 2])
