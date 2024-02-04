/*
 * @lc app=leetcode id=605 lang=golang
 *
 * [605] Can Place Flowers
 */

// @lc code=start
func canPlaceFlowers(flowerbed []int, n int) bool {
	num_bed := len(flowerbed)
	i := 0
	for i < num_bed && n > 0 {
		if i == 0 || flowerbed[i-1] == 0 && flowerbed[i] == 0 && i == num_bed - 1 || flowerbed[i+1] == 0 {
			flowerbed[i] = 1
			n--
			i += 2
		} else {
			i += 1
		}
	}
	return n == 0
}
// @lc code=end

