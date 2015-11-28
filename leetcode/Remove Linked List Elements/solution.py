class Solution(object):
    def removeElements(self, head, val):
        """
        :type head: ListNode
        :type val: int
        :rtype: ListNode
        """
        while head is not None and head.val == val:
            head = head.next
        if head is None:
            return head
        cur, next = head, head.next
        while next is not None:
            if next.val != val:
                cur.next = next
                cur = cur.next
            next = next.next
        cur.next = next
        return head