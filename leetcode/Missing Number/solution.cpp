// 36ms O(n), O(1)
// linked list
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        for (int i = 0; i < nums.size(); ++i){
            if (nums[i] == i) continue;
            int temp = nums[i];
            while (temp != i && temp != nums.size() && temp != nums[temp]){
                int t = nums[temp];
                nums[temp] = temp;
                temp = t;
            }
            if (temp == i) nums[i] = i;
        }
        for (int i = 0; i < nums.size(); ++i){
            if (nums[i] != i) return i;
        }
        return nums.size();
    }
};

// 36ms O(n), O(1)
// add solution
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int res = nums.size();
        for (int i = 0; i < nums.size(); ++i){
            res += i;
            res -= nums[i];
        }
        return res;
    }
};