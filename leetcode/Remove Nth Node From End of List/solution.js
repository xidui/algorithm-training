/**********
 * Remove Nth Node From End of List
 * https://leetcode.com/problems/remove-nth-node-from-end-of-list/
 * @author: Jerry Zou
 * @email: jerry.zry@outlook.com
 * 
 * Runtime: 184ms | 2015.12.1 15:19 GMT+08
 * Beats 40.38% JS submissions
 */

/**
 * Definition for singly-linked list.
 * function ListNode(val) {
 *     this.val = val;
 *     this.next = null;
 * }
 */
/**
 * @param {ListNode} head
 * @param {number} n
 * @return {ListNode}
 */
var removeNthFromEnd = function(head, n) {
  'use strict'
  
  let length = 0
    , map = new Map()
    , pesudoHead = new ListNode(-1)
    , iter = pesudoHead
  
  // add a pesudo head to avoid handling with edge cases
  pesudoHead.next = head
  
  while (iter !== null) {
    map.set(length++, iter)
    iter = iter.next
  }
  
  let prev = map.get(length - n - 1)
  prev.next = prev.next.next
  
  return pesudoHead.next
}