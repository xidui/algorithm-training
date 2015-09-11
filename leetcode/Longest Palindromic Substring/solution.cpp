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
};