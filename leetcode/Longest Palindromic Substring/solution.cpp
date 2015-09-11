class Solution {
public:
	// dynamic programming approach
	// complexity of O(n * n)
    string longestPalindrome(string s) {
        int dp[s.length()][s.length()];
        memset(dp, 0, sizeof(dp));
        for (int i = 0; i < s.length(); ++i) dp[i][i] = 1;
        int max = 1, start = 0;
        for (int i = 1; i < s.length(); ++i){
            for (int j = i - 1; j >= 0; --j){
                if (s[j] != s[i]) continue;
                if (j + 1 >= i - 1 || dp[j + 1][i - 1] == 1){
                    dp[j][i] = 1;
                }
                if (dp[j][i] == 1 && max < i - j + 1){
                    max = i - j + 1;
                    start = j;
                }
            }
        }
        return s.substr(start, max);
    }

    // the better solution from discuss
    // the max complexity is also O(n * n)
    // but this solution is faster
    string longestPalindrome(string s) {
        if (s.empty()) return "";
        if (s.size() == 1) return s;
        int min_start = 0, max_len = 1;
        for (int i = 0; i < s.size();) {
          if (s.size() - i <= max_len / 2) break;
          int j = i, k = i;
          while (k < s.size()-1 && s[k+1] == s[k]) ++k; // Skip duplicate characters.
          i = k+1;
          while (k < s.size()-1 && j > 0 && s[k + 1] == s[j - 1]) { ++k; --j; } // Expand.
          int new_len = k - j + 1;
          if (new_len > max_len) { min_start = j; max_len = new_len; }
        }
        return s.substr(min_start, max_len);
    }
};