// 64ms
class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        nth_element(nums.begin(), nums.begin() + nums.size() / 2, nums.end());
        int mid = *(nums.begin() + nums.size() / 2);

        #define N(i) (nums[(1 + (i) * 2) % (nums.size() | 1)])

        int i = 0, j = 0, k = nums.size() - 1;
        while (j <= k){
            if (N(j) > mid){
                swap(N(i++), N(j++));
            } else if (N(j) < mid) {
                swap(N(k--), N(j));
            } else{
                j++;
            }
        }
    }
};