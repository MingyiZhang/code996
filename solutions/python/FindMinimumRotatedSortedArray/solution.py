from typing import List


def find_min(nums: List[int]) -> int:
    left, right = 0, len(nums) - 1
    while left < right:
        mid = (left + right) // 2
        if nums[mid] > nums[right]:
            left = mid + 1
        else:
            right = mid
    return nums[left]


if __name__ == '__main__':
    assert (1 == find_min([3, 4, 5, 1, 2]))
    assert (0 == find_min([4, 5, 6, 7, 0, 1, 2]))
