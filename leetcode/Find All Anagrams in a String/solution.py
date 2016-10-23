class Solution(object):
    def findAnagrams(self, s, p):
        """
        :type s: str
        :type p: str
        :rtype: List[int]
        """
        list = []
        dic = {}
        
        for c in p:
            if dic.has_key(c):
                dic[c] += 1
            else:
                dic[c] = 1
        
        numToBeZero = len(dic)
        
        for index in range(len(s)):
            if dic.has_key(s[index]):
                dic[s[index]] -= 1
                if dic[s[index]] == 0:
                    numToBeZero -= 1
                    
            if index >= len(p) and dic.has_key(s[index - len(p)]):
                if dic[s[index - len(p)]] == 0:
                    numToBeZero += 1
                dic[s[index - len(p)]] += 1
       
            if numToBeZero == 0:
                list.append(index - len(p) + 1)
        
        return list