/*
 * @lc app=leetcode id=238 lang=golang
 *
 * [238] Product of Array Except Self
 */

// @lc code=start
func productExceptSelf(nums []int) []int {
	prod := 1
	zeros := 0
	for _, n := range nums {
		if n == 0 {
			zeros++
			if zeros > 1 {
				break
			}
		} else {
			prod *= n
		}
	}

	ans := make([]int, len(nums))

	if zeros > 1 {
		return ans
	}
	if zeros == 1 {
		for i, n := range nums {
			if n == 0 {
				ans[i] = prod
			}
		}
		return ans
	}
	for i, n := range nums {
		ans[i] = prod / n
	}
	return ans
    
}
// @lc code=end

