// O(n*n)
// 1400ms
// bad solution
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() < 2) return 0;
        int dp[prices.size()];
        memset(dp, 0, sizeof(dp));
        int ret = 0;
        for (int i = 1; i < prices.size(); ++i){
            for (int j = 0; j < i; ++j) {
                dp[i] = max(dp[i], dp[j] + prices[i] - prices[j]);
                if (i - j > 1) dp[i] = max(dp[i], dp[j]);
            }
            ret = max(ret, dp[i]);
        }
        return ret;
    }
};