from typing import List


def max_sub_array(nums: List[int]) -> int:
    pre_sum = 0
    max_sum = -float('inf')
    for x in nums:
        pre_sum = pre_sum + x if pre_sum > 0 else x
        max_sum = max(max_sum, pre_sum)
    return max_sum


if __name__ == '__main__':
    assert (6 == max_sub_array([-2, 1, -3, 4, -1, 2, 1, -5, 4]))
