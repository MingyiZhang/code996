/*
 * @lc app=leetcode id=1768 lang=golang
 *
 * [1768] Merge Strings Alternately
 */

// @lc code=start
func mergeAlternately(word1 string, word2 string) string {
	var len1, len2 int = len(word1), len(word2)
    var result string
	for i := 0; i < len1 || i < len2; i++ {
		if i < len1 {
			result += string(word1[i])
		}
		if i < len2 {
			result += string(word2[i])
		}
	}
	return result
    
}
// @lc code=end

