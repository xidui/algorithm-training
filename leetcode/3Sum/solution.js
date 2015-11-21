/**********
 * Solution to 3Sum
 * https://leetcode.com/problems/3sum/
 * @author: Jerry Zou
 * @email: jerry.zry@outlook.com
 * 
 * Runtime: 272ms
 * Beats 46.88% JS submissions
 * Note: Sort array first, then traverse the array and 
 *       use two pointer to find other two numbers.
 */

/**
 * @param {number[]} nums
 * @return {number[][]}
 */
var threeSum = function(nums) {
  "use strict"
  nums.sort(function(a, b) { return a - b })
  
  let len = nums.length
    , resultArr = []
    
  for (let i = 0; i < len; i++) {
    while (nums[i] === nums[i-1]) { ++i }
    let target = -nums[i]
      , j = i + 1
      , k = len - 1
    while (j < k) {
      if (target === nums[j] + nums[k]) {
        resultArr.push([nums[i], nums[j], nums[k]])
        while (nums[j] === nums[j+1]) { ++j }
        while (nums[k] === nums[k-1]) { --k }
        ++j, --k
      } else if (target < nums[j] + nums[k]) {
        --k
      } else {
        ++j
      }
    }
  }
  
  return resultArr
}