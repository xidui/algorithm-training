func lengthOfLongestSubstring(s string) int {
	pos := make([]int, 128, 128)
	start, ans:= 0, 0

	for i := 1; i <= len(s); i++ {
		if pos[s[i - 1]] == 0 || pos[s[i - 1]] <= start {
			pos[s[i - 1]] = i
			continue
		}
		if ans < i - 1 - start {
			ans = i - 1 - start
		}
		start = pos[s[i - 1]]
		pos[s[i - 1]] = i
	}

	if ans < len(s) - start {
		ans = len(s) - start
	}

	return ans
}