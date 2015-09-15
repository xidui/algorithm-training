class Solution {
public:
    // dynamic programming
    // 244ms with O(n * log(n)) approach
    int numSquares(int n) {
        int dp[n];
        dp[0] = 0;
        for (int i = 1; i <= n; ++i){
            dp[i] = n;
            for (int j = (int)sqrt(i); j > 0; --j){
                dp[i] = min(dp[i], dp[i - j * j] + 1);
            }
        }
        return dp[n];
    }
};