/**********
 * Swap Nodes in Pairs
 * https://leetcode.com/problems/swap-nodes-in-pairs/
 * @author: Jerry Zou
 * @email: jerry.zry@outlook.com
 * 
 * Runtime: 160ms | 2015.12.8 16:17 GMT+08
 * Beats 46.88% JS submissions
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
 * @return {ListNode}
 */
var swapPairs = function(head) {
  'use strict'
  
  let nextNode
    , fakeHead = new ListNode()
    , cursor = fakeHead
  
  fakeHead.next = head
  
  while (cursor.next && cursor.next.next) {
    nextNode = cursor.next
    cursor.next = nextNode.next
    nextNode.next = nextNode.next.next
    cursor.next.next = nextNode
    cursor = nextNode
  }
  
  return fakeHead.next
}