/****
 * Solution of https://leetcode.com/problems/valid-palindrome/
 * @author: Jerry Zou
 * @date: 2015.6.11
 **/

/**
 * Definition for singly-linked list.
 * function ListNode(val) {
 *     this.val = val;
 *     this.next = null;
 * }
 */
/**
 * @param {ListNode} head
 * @return {ListNode}
 */

// Runtime: 204ms
var mergeSortedList = function(headA, headB) {
    if (!headA) return headB
    if (!headB) return headA

    var head = new ListNode(-1),
        current = head
    while (headA && headB) {
        if (headA.val <= headB.val) {
            current.next = headA
            headA = headA.next
        } else {
            current.next = headB
            headB = headB.next
        }
        current = current.next
    }
    if (headA) current.next = headA
    else if (headB) current.next = headB

    return head.next
}

var sortList = function(head) {
    if (!head || !head.next) return head

    var middle = head,
        end = head,
        prev = middle

    // find the middle ListNode of the list
    while (end && end.next) {
        prev = middle
        middle = middle.next
        end = end.next.next
    }

    prev.next = null;

    return mergeSortedList(sortList(head), sortList(middle))
}