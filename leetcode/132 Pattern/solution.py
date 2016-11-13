class Solution(object):
    def find132pattern(self, nums):
        """
        :type nums: List[int]
        :rtype: bool
        """
        if len(nums) < 3:
            return False
        
        stack = [[nums[0], nums[0]]]
        min = nums[0]
        for cur in range(1, len(nums)):
            if nums[cur] < min:
                min = nums[cur]
                stack.append([min, min])
            else:
                while stack and nums[cur] > stack[-1][0]:
                    if nums[cur] < stack[-1][1]:
                        return True
                    else:
                        stack.pop()
                stack.append([min, nums[cur]])
                
        return False;