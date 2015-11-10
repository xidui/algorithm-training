# 64ms
# long and ugly
class Solution(object):
    def levelOrder(self, root):
        """
        :type root: TreeNode
        :rtype: List[List[int]]
        """
        ret = list()
        a = list()
        a.append(root)
        while len(a):
            c = list()
            b = list()
            for node in a:
                if node:
                    b.append(node.val)
                    c.append(node.left)
                    c.append(node.right)
            if len(b):
                ret.append(b)
            a = c
        return ret

# 64ms
# beautiful solution
class Solution(object):
    def levelOrder(self, root):
        """
        :type root: TreeNode
        :rtype: List[List[int]]
        """
        ans, level = [], [root]
        while root and level:
            ans.append([node.val for node in level])
            level = [kid for n in level for kid in (n.left, n.right) if kid]
        return ans