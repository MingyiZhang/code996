from typing import List

# # recursive version, a bit slow
# def find_single(nums: List[int], left: int, right: int) -> int:
#     if left == right:
#         return nums[left]
#
#     mid = (left + right) // 2
#     k = (mid - left) % 2
#     if k == 0:  # sub array has even size
#         if nums[mid] == nums[mid + 1]:
#             return find_single(nums, mid + 2, right)
#         elif nums[mid - 1] == nums[mid]:
#             return find_single(nums, left, mid - 2)
#         else:
#             return nums[mid]
#     elif k == 1:  # sub array has odd size
#         if nums[mid] == nums[mid + 1]:
#             return find_single(nums, left, mid - 1)
#         elif nums[mid - 1] == nums[mid]:
#             return find_single(nums, mid + 1, right)
#         else:
#             return nums[mid]
#
#
# def single_non_duplicate(nums: List[int]) -> int:
#     return find_single(nums, 0, len(nums) - 1)


def single_non_duplicate(nums: List[int]) -> int:
    left, right = 0, len(nums) - 1
    while left < right:
        mid = (left + right) // 2
        if nums[mid] != nums[mid + 1] and nums[mid] != nums[mid - 1]:
            return nums[mid]
        elif nums[mid] == nums[mid + 1]:
            if len(nums[mid:right + 1]) % 2 == 0:
                right = mid - 1
            else:
                left = mid + 2
        elif nums[mid - 1] == nums[mid]:
            if len(nums[left:mid]) % 2 == 0:
                right = mid - 2
            else:
                left = mid + 1
    return nums[left]


if __name__ == '__main__':
    assert (2 == single_non_duplicate([1, 1, 2, 3, 3, 4, 4, 8, 8]))
    assert (10 == single_non_duplicate([3, 3, 7, 7, 10, 11, 11]))
