// dynamic programming
// 396ms O(k * n)
// actually this solution is good enough
// if you treat those k > prices.size() / 2 as the "Best Time to Buy and Sell Stock III"
// after then it will run within 8ms
class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        // compress the prices
        if (prices.size() < 2) return 0;
        vector<int> p;
        int pre = INT32_MAX, i = 0; bool down = true;
        while (i < prices.size()){
            if ((down && prices[i] > pre) || (!down && prices[i] < pre)){
                p.push_back(pre);
                down = !down;
            }
            if (i == prices.size() - 1 && prices[i] >= pre){
                p.push_back(prices[i]);
                break;
            }
            pre = prices[i++];
        }

        // determine the dp size
        int trans = min((int)p.size() / 2, k);
        int dp_a[p.size() / 2 + 1];
        int dp_b[p.size() / 2 + 1];
        memset(dp_a, 0, sizeof(dp_a));
        memset(dp_b, 0, sizeof(dp_b));

        // calculate
        for (int k = 1; k <= trans; ++k){
            int temp = dp_a[0] - p[0];
            for (int j = 1; j <= p.size() / 2; ++j){
                dp_b[j] = max(dp_b[j - 1], p[2 * j - 1] + temp);
                temp = max(temp, dp_a[j] - p[2 * j]);
            }
            for (int i = 0; i < p.size() / 2 + 1; ++i){
                dp_a[i] = dp_a[i] + dp_b[i];
                dp_b[i] = dp_a[i] - dp_b[i];
                dp_a[i] = dp_a[i] - dp_b[i];
            }
            memset(dp_b, 0, sizeof(dp_b));
        }

        return dp_a[p.size() / 2];
    }
};

// another approach by others
// code is more beautiful
class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int len = prices.size();
        if (len<2) return 0;
        if (k>len/2){ // simple case
            int ans = 0;
            for (int i=1; i<len; ++i){
                ans += max(prices[i] - prices[i-1],0);
            }
            return ans;
        }
        int hold[k+1];
        int rele[k+1];
        for (int i=0;i<=k;++i){
            hold[i] = INT_MIN;
            rele[i] = 0;
        }
        int cur;
        for (int i=0; i<len; ++i){
            cur = prices[i];
            for(int j=k; j>0; --j){
                rele[j] = max(rele[j],hold[j] + cur);
                hold[j] = max(hold[j],rele[j-1] - cur);
            }
        }
        return rele[k];
    }
};