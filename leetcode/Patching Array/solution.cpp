// 8ms greedy solution
class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        long sum = 0, ans = 0;
        for (int i = 0; i < nums.size() && sum < n;){
            if (nums[i] > sum + 1){
                sum += sum + 1;
                ans++;
            } else {
                sum += nums[i];
                ++i;
            }
        }
        while (sum < n){
            sum += sum + 1;
            ans++;
        }
        return ans;
    }
};

// more precise solution
class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        long ptr = 0, sum = 0, ans = 0;
        while (sum < n){
            if (ptr < nums.size() && nums[ptr] <= sum + 1){
                sum += nums[ptr];
                ++ptr;
                continue;
            }
            sum += sum + 1;
            ans++;
        }
        return ans;
    }
};