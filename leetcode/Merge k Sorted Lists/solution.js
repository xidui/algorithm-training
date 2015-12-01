/**********
 * Merge K Sorted Lists
 * https://leetcode.com/problems/merge-k-sorted-lists/
 * @author: Jerry Zou
 * @email: jerry.zry@outlook.com
 * 
 * Runtime: 224ms | 2015.12.1 21:17 GMT+08
 * Beats 64.29% JS submissions
 * Note: it's suitable to use Min Heap to solve this problem
 */

/**
 * Definition for singly-linked list.
 * function ListNode(val) {
 *     this.val = val;
 *     this.next = null;
 * }
 */
/**
 * @param {ListNode[]} lists
 * @return {ListNode}
 */
var mergeKLists = function(lists) {
  'use strict'
  
  // heap method
  Array.prototype.$makeHeap = function(prop) {
    let copy = []
    for (let i = 0; i < this.length; ++i) copy.push(this[i])
    
    this.length = 0
    this.$heapProp = prop
    for (let i = 0; i < copy.length; ++i) this.$insert(copy[i])
    
    return this
  }
  
  Array.prototype.$insert = function(val) {
    this.push(val)
    
    let current = this.length - 1
      , parent
      , prop = this.$heapProp
    
    while (current !== 0) {
      parent = Math.floor((current - 1) / 2)
      let compareResult = typeof prop != 'undefined' ? this[parent][prop] > this[current][prop] : this[parent] > this[current]
      if (compareResult) {
        this.$swap(parent, current)
      } else {
        break
      }
      current = parent
    }
    
    return this
  }
  
  Array.prototype.$shiftDown = function(index) {
    let left = 2 * index + 1
      , right = 2 * index + 2
      , prop = this.$heapProp
      , currVal = this[index]
      , leftVal = this[left]
      , rightVal = this[right]
    
    if (typeof prop != 'undefined') {
      currVal = currVal[prop]
      leftVal = leftVal ? leftVal[prop] : Number.POSITIVE_INFINITY
      rightVal = rightVal ? rightVal[prop] : Number.POSITIVE_INFINITY
    }
    
    let min = Math.min(currVal, leftVal, rightVal)
    
    if (currVal > min) {
      if (leftVal < rightVal) {
        this.$swap(index, left)
        this.$shiftDown(left)
      } else if (leftVal >= rightVal) {
        this.$swap(index, right)
        this.$shiftDown(right)
      }
    }
    return this
  }
  
  Array.prototype.$swap = function(i, j) {
    let tmp = this[i]
    this[i] = this[j]
    this[j] = tmp
    return this
  }
  
  lists = lists.filter(function(list) {
    return list
  })
  lists.$makeHeap('val')
  
  let head = new ListNode()
    , tail = head
  
  while (lists.length > 0) {
    tail = tail.next = lists[0]
    lists[0] = lists[0].next
    if (!lists[0]) {
      lists[0] = lists[lists.length - 1]
      --lists.length
    }
    if (!lists.length) break
    lists.$shiftDown(0)
  }
  
  return head.next
}