class Solution(object):
    def isValidSerialization(self, preorder):
        """
        :type preorder: str
        :rtype: bool
        """
        nodes, l = preorder.split(','), []
        for n in nodes:
            l.append(n)
            while len(l) > 2 and l[len(l) - 1] == "#" and l[len(l) - 2] == "#":
                if l[-3] == "#":
                    return False
                l = l[:-3]
                l.append(n)
        return len(l) == 1 and l[0] == "#"
        