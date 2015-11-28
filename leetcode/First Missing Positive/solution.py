// 48ms
// change the value of the original array
class Solution(object):
    def firstMissingPositive(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        if len(nums) == 0:
            return 1
        m = max(max(nums), len(nums))
        for i in range(len(nums)):
            n = nums[i] - 1
            while n < len(nums) and n >= 0:
                temp = n
                n = nums[n] - 1
                nums[temp] = m + 1
        for i in range(len(nums)):
            if nums[i] != m + 1:
                return i + 1
        return m + 1
