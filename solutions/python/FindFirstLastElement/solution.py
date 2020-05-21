from typing import List


def search_range(nums: List[int], target: int) -> List[int]:
    left, right = 0, len(nums) - 1
    while left < right:
        mid = (left + right) // 2
        if nums[mid] < target:
            left = mid + 1
        else:
            right = mid
    if nums[left] != target:
        return [-1, -1]
    first = left

    left, right = first, len(nums) - 1
    while left < right:
        mid = (left + right + 1) // 2
        if nums[mid] > target:
            right = mid - 1
        else:
            left = mid
    return [first, right]


if __name__ == '__main__':
    assert ([3, 4] == search_range([5, 7, 7, 8, 8, 10], 8))


