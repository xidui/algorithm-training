// 92ms O(n * n)
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int dp[nums.size()];
        int ret = 0;
        for (int i = 0; i < nums.size(); ++i){
            if (i == 0){
                dp[i] = 1;
                ret = max(ret, dp[i]);
                continue;
            }
            dp[i] = 1;
            for (int j = i - 1; j >= 0; --j){
                if (nums[j] >= nums[i]) continue;
                dp[i] = max(dp[i], dp[j] + 1);
            }
            ret = max(ret, dp[i]);
        }
        return ret;
    }
};

// very excellent solution!
// by others 4ms
// O(n * log n)
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> res;
        for(int i=0; i<nums.size(); i++) {
            auto it = std::lower_bound(res.begin(), res.end(), nums[i]);
            if(it==res.end()) res.push_back(nums[i]);
            else *it = nums[i];
        }
        return res.size();
    }
};