// 44ms solution
// O(n * n)
class Solution(object):
    def isAdditiveNumber(self, num):
        """
        :type num: str
        :rtype: bool
        """
        for a in range(len(num) / 2):
            for b in range(len(num) / 2):
                temp = num
                x, y, temp = temp[0:a + 1], temp[a + 1:a + b + 2], temp[a + b + 2:]
                if (len(x) > 1 and x[0] == '0') or (len(y) > 1 and y[0] == '0'):
                    continue
                x, y = int(x), int(y)
                if len(temp) == 0:
                    return False
                while len(temp):
                    add = str(x + y)
                    if len(add) <= len(temp) and add == temp[0:len(add)]:
                        temp = temp[len(add):]
                        x, y = y, int(add)
                        continue
                    break
                if len(temp) == 0:
                    return True
        return False