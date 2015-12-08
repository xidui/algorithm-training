/**********
 * Remove Duplicates from Sorted Array
 * https://leetcode.com/problems/remove-duplicates-from-sorted-array/
 * @author: Jerry Zou
 * @email: jerry.zry@outlook.com
 * 
 * Runtime: 212ms | 2015.12.8 19:37 GMT+08
 * Beats 60.16% JS submissions
 */

/**
 * @param {number[]} nums
 * @return {number}
 */
var removeDuplicates = function(nums) {
  'use strict'
  
  let len = nums.length
  
  if (len < 2) return len
  
  let count = 1
  
  for (let i = 1; i < len; ++i) {
    if (nums[i] != nums[i - 1]) {
      nums[count++] = nums[i]
    }
  }
  
  nums.length = count
  
  return count
}