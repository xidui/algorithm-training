/**********
 * Merge Two Sorted Lists
 * https://leetcode.com/problems/merge-two-sorted-lists/
 * @author: Jerry Zou
 * @email: jerry.zry@outlook.com
 * 
 * Runtime: 184ms | 2015.12.1 19:30 GMT+08
 * Beats 51.25% JS submissions
 */

/**
 * Definition for singly-linked list.
 * function ListNode(val) {
 *     this.val = val;
 *     this.next = null;
 * }
 */
/**
 * @param {ListNode} l1
 * @param {ListNode} l2
 * @return {ListNode}
 */
var mergeTwoLists = function(l1, l2) {
    'use strict'
    
    let head = new ListNode()
      , tail = head
    
    while (l1 !== null && l2 !== null) {
      if (l1.val < l2.val) {
        tail = tail.next = l1
        l1 = l1.next
      } else {
        tail = tail.next = l2
        l2 = l2.next
      }
    }
    
    if (l1 !== null) tail.next = l1
    if (l2 !== null) tail.next = l2
    
    return head.next
}