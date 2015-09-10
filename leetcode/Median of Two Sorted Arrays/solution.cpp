class Solution {
public:
	// the complexity is O(m + n)
	// but the required is O(log(m + n))
	// so this solution is not the best
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int total = nums1.size() + nums2.size();
        int ptr1 = -1, ptr2 = -1, flag = 0, cur;
        while (flag++ < (total + 1) / 2){
            if (ptr1 + 1 == nums1.size()){
                if (nums2[ptr2++ + 1] > cur) cur = nums2[ptr2];
                continue;
            }
            if (ptr2 + 1 == nums2.size()){
                if (nums1[ptr1++ + 1] > cur) cur = nums1[ptr1];
                continue;
            }
            if (nums1[ptr1 + 1] < nums2[ptr2 + 1]) cur = nums1[ptr1++ + 1];
            else cur = nums2[ptr2++ + 1];
        }
        if (total % 2 == 1) return cur;
        int next;
        if (ptr2 + 1 == nums2.size()) next = nums1[ptr1 + 1];
        else if (ptr1 + 1 == nums1.size()) next = nums2[ptr2 + 1];
        else next = min(nums2[ptr2 + 1], nums1[ptr1 + 1]);
        return (double)(cur + next) / 2;
    }
};