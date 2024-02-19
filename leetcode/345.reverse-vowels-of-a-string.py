#
# @lc app=leetcode id=345 lang=python3
#
# [345] Reverse Vowels of a String
#

# @lc code=start
class Solution:
    
    def reverseVowels(self, s: str) -> str:
        vowels = {"a", "e", "i", "o", "u", "A", "E", "I", "O", "U"}
        chars = list(s)
        start = 0
        end = len(s) - 1
        while start <= end:
            if chars[start] in vowels and chars[end] in vowels:
                chars[start], chars[end] = chars[end], chars[start]
                start += 1
                end -= 1
            elif chars[start] not in vowels:
                start += 1
            elif chars[end] not in vowels:
                end -= 1
        return "".join(chars)


        
# @lc code=end

