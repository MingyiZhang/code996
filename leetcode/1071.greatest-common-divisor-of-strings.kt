/*
 * @lc app=leetcode id=1071 lang=kotlin
 *
 * [1071] Greatest Common Divisor of Strings
 */

// @lc code=start
class Solution {
    fun gcdOfStrings(str1: String, str2: String): String {
        if (str1.length < str2.length) {
            return gcdOfStrings(str2, str1)
        }
        if (str2.isEmpty()) {
            return str1
        }
        if (!str1.startsWith(str2)) {
            return ""
        }
        return gcdOfStrings(str1.substring(str2.length), str2)
    }
}
// @lc code=end

