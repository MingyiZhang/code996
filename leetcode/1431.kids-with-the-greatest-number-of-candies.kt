/*
 * @lc app=leetcode id=1431 lang=kotlin
 *
 * [1431] Kids With the Greatest Number of Candies
 */

// @lc code=start
class Solution {
    fun kidsWithCandies(candies: IntArray, extraCandies: Int): List<Boolean> {
       var maximum = 0
       for (c in candies) {
         if (c > maximum) {
           maximum = c
         }
       }
       val limit = maximum - extraCandies
       val result = mutableListOf<Boolean>()
       for (c in candies) {
         result.add(c >= limit)
       }
       return result 
        
    }
}
// @lc code=end

