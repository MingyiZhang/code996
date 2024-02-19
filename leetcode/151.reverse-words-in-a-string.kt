/*
 * @lc app=leetcode id=151 lang=kotlin
 *
 * [151] Reverse Words in a String
 */

// @lc code=start
class Solution {
    fun reverseWords(s: String): String =
            s.split(" ").filterNot { it.isEmpty() }.reversed().joinToString(separator = " ")
}
// @lc code=end
