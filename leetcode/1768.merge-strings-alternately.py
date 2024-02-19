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
        result = ""
        i = 0
        while i < max(len1, len2):
            if i < len1:
                result += word1[i]
            if i < len2:
                result += word2[i]
            i += 1
        return result


        
        # len1 = len(word1)
        # len2 = len(word2)
        # result = ""
        # i = 0
        # while i < len1 and i < len2:
        #     result += word1[i] + word2[i]
        #     i += 1
        # while i < len1:
        #     result += word1[i]
        #     i += 1
        # while i < len2:
        #     result += word2[i]
        #     i += 1
        # return result
        
# @lc code=end

