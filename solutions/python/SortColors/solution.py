from typing import List


def sortColors(nums: List[int]) -> None:
    #  nums[0...j-1] == 0, nums[j...i-1] == 1, nums[k+1...n-1] == 2
    j = 0
    i = 0
    k = len(nums) - 1
    while i <= k:
        if nums[i] == 0:
            nums[i], nums[j] = nums[j], nums[i]
            j += 1
            i += 1
        elif nums[i] == 1:
            i += 1
        else:  # nums[i] == 2
            nums[i], nums[k] = nums[k], nums[i]
            k -= 1


if __name__ == '__main__':
    input1 = [2, 0, 2, 1, 1, 0]
    sortColors(input1)
    assert ([0, 0, 1, 1, 2, 2] == input1)
