from typing import List
from random import randint, seed


def partition(nums: List[int], l: int, r: int) -> int:
    rd = randint(l, r)
    nums[l], nums[rd] = nums[rd], nums[l]
    v = nums[l]
    # nums[l+1...j] > v, nums[j+1...i-1] <= v
    j = l
    for i in range(l + 1, r + 1):
        if nums[i] > v:
            nums[i], nums[j + 1] = nums[j + 1], nums[i]
            j += 1
    nums[l], nums[j] = nums[j], nums[l]
    return j


def find_kth_largest(nums: List[int], k: int) -> int:
    seed()
    left = 0
    right = len(nums) - 1
    k_idx = k - 1
    while left <= right:
        p = partition(nums, left, right)
        if p == k_idx:
            return nums[p]
        elif p < k_idx:
            left = p + 1
        else:  # p > k_idx
            right = p - 1


if __name__ == '__main__':
    assert(5 == find_kth_largest([3, 2, 1, 5, 6, 4], 2))
    assert(4 == find_kth_largest([3, 2, 3, 1, 2, 4, 5, 5, 6], 4))
