#
# @lc app=leetcode id=1768 lang=python3
#
# [1768] Merge Strings Alternately
#

# @lc code=start
class Solution:
    def mergeAlternately(self, word1: str, word2: str) -> str:
        len1 = len(word1)
        len2 = len(word2)
        i = 0
        j = 0
        result = ""
        while i < len1 and j < len2:
            result += word1[i]
            result += word2[j]
            i += 1
            j += 1
        while i < len1:
            result += word1[i]
            i += 1
        while j < len2:
            result += word2[j]
            j += 1
        return result 
        
# @lc code=end

