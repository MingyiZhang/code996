/*
 * @lc app=leetcode id=605 lang=kotlin
 *
 * [605] Can Place Flowers
 */

// @lc code=start
class Solution {
    fun canPlaceFlowers(flowerbed: IntArray, n: Int): Boolean {
        val num_bed = flowerbed.size
        var count = n
        var i = 0
        while (i < num_bed && count > 0) {
            if ((i == 0 || flowerbed[i - 1] == 0) && flowerbed[i] == 0 && (i == num_bed - 1 || flowerbed[i + 1] == 0)) {
                flowerbed[i] = 1
                count--
                i += 2
            } else {
                i++
            }
        }
        return count == 0
    }
}
// @lc code=end

