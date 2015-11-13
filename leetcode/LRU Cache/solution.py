# 836ms very slow solution
# because when updating the queue is not O(1)
from collections import deque

class LRUCache(object):
    def __init__(self, capacity):
        """
        :type capacity: int
        """
        self.capacity = capacity
        self.cache = dict()
        self.order = deque()

    def get(self, key):
        """
        :rtype: int
        """
        if key not in self.cache:
            return -1
        self.order.remove(key)
        self.order.append(key)
        return self.cache[key]

    def set(self, key, value):
        """
        :type key: int
        :type value: int
        :rtype: nothing
        """
        if key in self.cache:
            self.order.remove(key)
        self.cache[key] = value
        self.order.append(key)
        if len(self.cache) > self.capacity:
            old = self.order.popleft()
            del self.cache[old]