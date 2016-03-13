# 57ms
class Solution(object):
    def increasingTriplet(self, nums):
        """
        :type nums: List[int]
        :rtype: bool
        """
        least_first, least_second = None, None
        for n in nums:
            if least_first is None or n < least_first:
                least_first = n
                continue
            if (least_second is None or n < least_second) and n > least_first:
                least_second = n
                continue
            if least_second is not None and n > least_second:
                return True
        return False
