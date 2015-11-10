# 60ms
# almost the same solution with #102
class Solution(object):
    def levelOrderBottom(self, root):
        """
        :type root: TreeNode
        :rtype: List[List[int]]
        """
        ans, level = [], [root]
        while root and level:
            temp = ans
            ans = [[node.val for node in level]]
            ans.extend(temp)
            level = [kid for n in level for kid in (n.left, n.right) if kid]
        return ans