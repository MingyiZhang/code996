#
# @lc app=leetcode id=605 lang=python3
#
# [605] Can Place Flowers
#

# @lc code=start
class Solution:
    def canPlaceFlowers(self, flowerbed: List[int], n: int) -> bool:
        num_bed = len(flowerbed)
        i = 0
        while i < num_bed and n > 0:
            if (i == 0 or flowerbed[i-1] == 0) and flowerbed[i] == 0 and (i == num_bed - 1 or flowerbed[i+1] == 0):
                flowerbed[i] = 1
                n -= 1
                i += 2
            else:
                i += 1
        return n == 0

        
# @lc code=end

