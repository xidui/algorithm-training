// 8ms
class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int *first = NULL, *second = NULL;
        for (int i = 0; i < nums.size(); ++i) {
            if (first == NULL || nums[i] < *first) {
                first = &nums[i];
                continue;
            }
            if ((second == NULL || nums[i] < *second) && nums[i] > *first) {
                second = &nums[i];
                continue;
            }
            if (second != NULL && nums[i] > *second) return true;
        }
        return false;
    }
};