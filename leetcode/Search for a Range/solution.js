/**********
 * Search for a Range
 * https://leetcode.com/problems/search-for-a-range/
 * @author: Jerry Zou
 * @email: jerry.zry@outlook.com
 * 
 * Runtime: 168ms | 2015.12.19 22:23 GMT+08
 * Beats 52.38% JS submissions
 */

/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number[]}
 */
var searchRange = function(nums, target) {
	'use strict'
	
	if (target > nums[nums.length - 1] || target < nums[0]) return [-1, -1]
	return search(nums, 0, nums.length - 1, target)
		
  function search(nums, start, end, target) {
    if (start > end) return [-1, -1]
		let middle = Math.floor((end + start) / 2)
    if (nums[middle] > target) return search(nums, start, middle - 1, target)
    else if (nums[middle] < target) return search(nums, middle + 1, end, target)
    else {
      let left = search(nums, start, middle - 1, target)[0]
      let right = search(nums, middle + 1, end, target)[1]
      return [left == -1 ? middle : left, right == -1 ? middle : right]
    }
	}
}