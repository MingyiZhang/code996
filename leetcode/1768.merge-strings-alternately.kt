/*
 * @lc app=leetcode id=1768 lang=kotlin
 *
 * [1768] Merge Strings Alternately
 */

// @lc code=start
class Solution {
    fun mergeAlternately(word1: String, word2: String): String {
        val len1 = word1.length
        val len2 = word2.length
        val result = StringBuilder()
        (0..< maxOf(len1, len2)).forEach {
            if (it < len1) {
                result.append(word1[it])
            }
            if (it < len2) {
                result.append(word2[it])
            }
        }
        return result.toString()
    }
}
// @lc code=end

