// 1752ms
class Solution {
public:
    unordered_map<int, int> dp;

    int recur(vector<int>& coins, int amount) {
        if (amount < 0) return -1;
        if (dp.find(amount) != dp.end()) return dp[amount];
        int cur = INT32_MAX;
        for (int i = 0; i < coins.size(); ++i){
            int temp = recur(coins, amount - coins[i]);
            if (temp >= 0) cur = min(cur, temp + 1);
        }
        if (cur > 0 && cur != INT32_MAX)
            return dp[amount] = cur;
        else
            return dp[amount] = -1;
    }

    int coinChange(vector<int>& coins, int amount) {
        dp[0] = 0;
        return recur(coins, amount);
    }
};

// 152ms
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int dp[amount + 1];
        memset(dp, 0, sizeof(dp));
        for (int i = 1; i <= amount; ++i){
            dp[i] = INT32_MAX;
            for (auto coin : coins){
                if (i >= coin && dp[i - coin] != -1){
                    dp[i] = min(dp[i], dp[i - coin] + 1);
                }
            }
            if (dp[i] == INT32_MAX) dp[i] = -1;
        }
        return dp[amount];
    }
};

// 124ms
class Solution {
public:
    int* dp;

    int recur(vector<int>& coins, int amount) {
        if (amount < 0) return -1;
        if (dp[amount] != INT32_MAX) return dp[amount];
        for (int i = 0; i < coins.size(); ++i){
            int temp = recur(coins, amount - coins[i]);
            if (temp >= 0) dp[amount] = min(dp[amount], temp + 1);
        }
        if (dp[amount] == INT32_MAX) dp[amount] = -1;
        return dp[amount];
    }

    int coinChange(vector<int>& coins, int amount) {
        dp = new int[amount + 1];
        dp[0] = 0;
        for (int i = 1; i <= amount; ++i){
            dp[i] = INT32_MAX;
        }
        return recur(coins, amount);
    }
};