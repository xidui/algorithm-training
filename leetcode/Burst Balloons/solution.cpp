// recursive solution
// 48ms
// the basic idea is inspired by https://leetcode.com/discuss/72216/share-some-analysis-and-explanations

class Solution {
public:
    int dp[500][500];

    int recur(int s, int e, vector<int>& nums, int left, int right){
        if (s > e) return 0;
        if (dp[s][e] != 0) return dp[s][e];
        if (s == e) return dp[s][e] = nums[s] * left * right;
        for (int i = s; i <= e; ++i){
            int current = nums[i] * left * right;
            int l = recur(s, i - 1, nums, left, nums[i]);
            int r = recur(i + 1, e, nums, nums[i], right);
            dp[s][e] = max(dp[s][e], current + l + r);
        }
        return dp[s][e];
    }

    int maxCoins(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        memset(dp, 0, sizeof(dp));
        recur(0, nums.size() - 1, nums, 1, 1);
        return dp[0][nums.size() - 1];
    }
};
