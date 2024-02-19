/*
 * @lc app=leetcode id=345 lang=golang
 *
 * [345] Reverse Vowels of a String
 */

// @lc code=start
func reverseVowels(s string) string {
	start, end := 0, len(s) - 1
	runes := make([]rune, len(s))
	for i, r := range s {
		runes[i] = r
	}

	for start <= end {
		if isVowels(runes[start]) && isVowels(runes[end]) {
			temp := runes[start]
			runes[start] = runes[end]
			runes[end] = temp
			start++
			end--
		} else if !isVowels(runes[start]) {
			start++
		} else if !isVowels(runes[end]) {
			end--
		}
	}
	return string(runes[:])
}

func isVowels(r rune) bool {
	return r == 'a' || r == 'e' || r == 'i' || r == 'o' || r == 'u' || r == 'A' || r == 'E' || r == 'I' || r == 'O' || r == 'U'
}
// @lc code=end

