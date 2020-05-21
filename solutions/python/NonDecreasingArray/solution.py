from typing import List


def check_possibility(nums: List[int]) -> bool:
    cnt = 0
    for i in range(1, len(nums)):
        if nums[i - 1] <= nums[i]:
            continue

        if i >= 2 and nums[i - 2] > nums[i]:
            nums[i] = nums[i - 1]
        else:
            nums[i - 1] = nums[i]
        cnt += 1
        if cnt > 1:
            return False
    return True

    # first attempt
    # if len(nums) < 2:
    #     return True
    # cnt = 0
    # for i in range(len(nums) - 1):
    #     if nums[i] <= nums[i + 1]:
    #         continue
    #     if cnt:
    #         return False
    #     else:
    #         left = -float('inf') if i == 0 else nums[i - 1]
    #         right = float('inf') if i + 1 == len(nums) - 1 else nums[i + 2]
    #         if left <= nums[i] <= right:
    #             cnt += 1
    #             nums[i + 1] = nums[i]
    #         elif left <= nums[i + 1] <= right:
    #             cnt += 1
    #             nums[i] = nums[i + 1]
    #         else:
    #             return False
    # return True


if __name__ == '__main__':
    assert(check_possibility([4, 2, 3]))
    assert(not check_possibility([4, 2, 1]))

