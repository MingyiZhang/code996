/*
 * @lc app=leetcode id=1431 lang=golang
 *
 * [1431] Kids With the Greatest Number of Candies
 */

// @lc code=start
func kidsWithCandies(candies []int, extraCandies int) []bool {
	maximum := 0
	for _, c := range candies {
		if c > maximum {
			maximum = c
		}
	}
	limit := maximum - extraCandies
	result := make([]bool, len(candies))
	for i, c := range candies {
		if c >= limit {
			result[i] = true
		}
	}
	return result
}
// @lc code=end

