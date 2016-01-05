/**********
 * Single Number
 * https://leetcode.com/problems/single-number/
 * @author: Jerry Zou
 * @email: jerry.zry@outlook.com
 * 
 * Runtime: 172ms | 2016.1.5 21:26 GMT+08
 * Beats 37.38% JS submissions
 */

/**
 * @param {number[]} nums
 * @return {number}
 */
var singleNumber = function(nums) {
  'use strict'
  let map = new Map()
    , length = nums.length
  for (let i = 0; i < length; i++) {
    if (map.has(nums[i])) map.delete(nums[i])
    else map.set(nums[i], true)
  }
  return map.keys().next().value
}