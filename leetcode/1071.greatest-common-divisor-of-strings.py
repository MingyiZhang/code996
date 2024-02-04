#
# @lc app=leetcode id=1071 lang=python
#
# [1071] Greatest Common Divisor of Strings
#

# @lc code=start
class Solution(object):
    def gcdOfStrings(self, str1, str2):
        """
        :type str1: str
        :type str2: str
        :rtype: str
        """
        if len(str1) < len(str2):
            return self.gcdOfStrings(str2, str1)
        if not str1.startswith(str2):
            return ""
        if str2 == "":
            return str1
        return self.gcdOfStrings(str1[len(str2):], str2)
        
# @lc code=end

