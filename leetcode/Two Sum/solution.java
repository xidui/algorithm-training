public class Solution {
    public int[] twoSum(int[] nums, int target) {
        int[] index = new int[2];
        HashMap<Integer, Integer> map = new HashMap<Integer, Integer>();
        
        for (int i = 0; i < nums.length; i++) {
            if (map.get(nums[i]) != null) {
                index[0] = map.get(nums[i]);
                index[1] = i;
                return index;
            }
            
            map.put(target - nums[i], i);
        }
        return index;
    }
}