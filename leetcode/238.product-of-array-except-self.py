#
# @lc app=leetcode id=238 lang=python3
#
# [238] Product of Array Except Self
#

# @lc code=start
class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        prod = 1
        num_zeros = 0
        for n in nums:
            if n == 0:
                num_zeros += 1
                if num_zeros > 1:
                    break
            else:
                prod *= n
        if num_zeros > 1:
            return [0 for n in nums]
        if num_zeros == 1:
            return [0 if n != 0 else prod for n in nums]
        return [int(prod / n) for n in nums]
        
# @lc code=end

