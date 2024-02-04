/*
 * @lc app=leetcode id=1071 lang=golang
 *
 * [1071] Greatest Common Divisor of Strings
 */

// @lc code=start
func gcdOfStrings(str1 string, str2 string) string {
	if len(str1) < len(str2) {
		return gcdOfStrings(str2, str1)
	}
	if str1[:len(str2)] != str2 {
		return ""
	}
	if len(str2) == 0 {
		return str1 
	}
	return gcdOfStrings(str1[len(str2):], str2)
}
// @lc code=end

