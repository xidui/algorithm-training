/**********
 * Solution to 3Sum Closest
 * https://leetcode.com/problems/3sum-closest/
 * @author: Jerry Zou
 * @email: jerry.zry@outlook.com
 * 
 * Runtime: 168ms
 * Beats 22.22% JS submissions
 * Note: Sort array first, then traverse the array and 
 *       use two pointer to find other two numbers.
 */

/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number}
 */
var threeSumClosest = function(nums, target) {
  "use strict"
	let minSum = Number.MAX_SAFE_INTEGER
		, diff = Number.MAX_SAFE_INTEGER
		, len = nums.length
		, sum
	
	nums.sort(function(a, b) { return a - b })
		
	for (let i = 0; i < len; ++i) {
		let j = i + 1
			, k = len - 1
		while (j < k) {
			sum = nums[i] + nums[j] + nums[k]j
			if (Math.abs(sum - target) < diff) {
				minSum = sum
				diff = Math.abs(minSum - target)
			}
			if (sum === target) {
				return target
			} else if (sum < target) {
				++j
			} else if (sum > target) {
				--k
			}
		}
	}
	
	return minSum
}