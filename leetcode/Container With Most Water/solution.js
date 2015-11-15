/**********
 * Container With Most Water
 * https://leetcode.com/problems/container-with-most-water/
 * @author: Jerry Zou
 * @email: jerry.zry@outlook.com
 * 
 * Runtime: 152ms
 * Beats 5.21% JS submissions
 * Explaination: https://leetcode.com/discuss/41527/simple-and-fast-c-c-with-explanation
 */

/**
 * @param {number[]} height
 * @return {number}
 */
var maxArea = function(height) {
  var max = 0
    , len = height.length
    , left = 0
    , right = len - 1
    , current
    , h

  while (left < right) {
    h = Math.min(height[left], height[right]);
    current = (right - left) * h
    if (current > max) max = current
    while (left < right && height[right] <= h) --right
    while (left < right && height[left] <= h) ++left
  }

  return max
};