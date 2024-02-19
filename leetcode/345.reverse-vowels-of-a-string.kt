/*
 * @lc app=leetcode id=345 lang=kotlin
 *
 * [345] Reverse Vowels of a String
 */

// @lc code=start
class Solution {

    private val VOWELS = setOf(
        'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'
    )

    fun reverseVowels(s: String): String {
        var start = 0
        var end = s.length - 1
        val chars = s.map { it }.toMutableList()
        while (start <= end) {
            if (chars[start] in VOWELS && chars[end] in VOWELS) {
                var temp = chars[start]
                chars[start] = chars[end]
                chars[end] = temp
                start++
                end--
            } else if (chars[start] !in VOWELS) {
                start++
            } else if (chars[end] !in VOWELS) {
                end--
            }
        }
        return chars.joinToString(separator="")
    }
}
// @lc code=end

