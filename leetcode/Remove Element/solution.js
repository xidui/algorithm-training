/**********
 * Remove Element
 * https://leetcode.com/problems/remove-element/
 * @author: Jerry Zou
 * @email: jerry.zry@outlook.com
 * 
 * Runtime: 160ms | 2015.12.15 21:04 GMT+08
 * Beats 84.85% JS submissions
 */

/**
 * @param {number[]} nums
 * @param {number} val
 * @return {number}
 */
var removeElement = function(nums, val) {
  'use strict'
  
  let lastPos = nums.length - 1
  
  for (let i = 0; i <= lastPos; ++i) {
    if (nums[i] === val) {
      nums[i--] = nums[lastPos--]
    }
  }
  
  nums.length = lastPos + 1
  return nums.length
}