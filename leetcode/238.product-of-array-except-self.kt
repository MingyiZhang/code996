/*
 * @lc app=leetcode id=238 lang=kotlin
 *
 * [238] Product of Array Except Self
 */

// @lc code=start
class Solution {
    fun productExceptSelf(nums: IntArray): IntArray {
        var prod = 1
        var numZeros = 0
        for (n in nums) {
            if (n == 0) {
                numZeros++
                if (numZeros > 1) {
                    break
                }
            } else {
                prod *= n
            }
        }
        if (numZeros > 1) {
            return IntArray(nums.size) { 0 }
        }
        if (numZeros == 1) {
            return IntArray(nums.size) {
                if (nums[it] == 0) {
                    prod
                } else {
                    0
                }
            }
        }
        return IntArray(nums.size) { prod / nums[it] }
    }
}
// @lc code=end

