// 12ms fast enough
// but the solution is too long
// is there any better
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if (nums.size() == 0) return vector<int>(2, -1);
        int s = 0, e = nums.size() - 1, m = (s + e) / 2;
        if ((nums[s] < target && nums[e] < target)
            || (nums[s] > target && nums[e] > target)) return vector<int>(2, -1);

        // find one target
        if (nums[s] == target)m = s;
        else if(nums[e] == target) m = e;
        else while (nums[m] != target && m != s){
            if (nums[m] > target) e = m;
            else s = m;
            m = (s + e) / 2;
        }
        if (m == s && nums[m] != target) return vector<int>(2, -1);

        // find the start
        s = 0, e = m;
        int ptr1 = (s + e + 1) / 2;
        while (ptr1 != e){
            if (nums[ptr1] == target) e = ptr1;
            else s = ptr1;
            ptr1 = (s + e + 1) / 2;
        }

        // find the end
        s = m, e = nums.size() - 1;
        int ptr2 = (s + e) / 2;
        if (nums[e] == target) ptr2 = e;
        else while (ptr2 != s){
            if (nums[ptr2] == target) s = ptr2;
            else e = ptr2;
            ptr2 = (s + e) / 2;
        }

        // return result
        vector<int> ret;
        ret.push_back(ptr1);
        ret.push_back(ptr2);
        return ret;
    }
};