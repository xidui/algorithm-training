/**********
 * Solution to Median of Two Sorted Arrays
 * https://leetcode.com/problems/median-of-two-sorted-arrays/
 * @author: Jerry Zou
 * @email: jerry.zry@outlook.com
 * 
 * Runtime: 308ms
 * Beats 25.00% JS submissions
 * Notes: If you know how to find the k-th minimum element of two arrays,
 *        you will know how to solve this problem.
 */

/**
 * @param {number[]} nums1
 * @param {number[]} nums2
 * @return {number}
 */
var findMedianSortedArrays = function(nums1, nums2) {
  
  var m = nums1.length
    , n = nums2.length
    , k
    
  // make sure that nums1.length > nums2.length (to make the algorithm faster)
  if (m < n) return findMedianSortedArrays(nums2, nums1);
  
  if (n == 0) {
    k = m >> 1;
    if (m % 2) return nums1[k]
    else return (nums1[k] + nums1[k-1]) / 2
  }

  // simplify edge cases
  Array.prototype.get = function(index) {
    // The base of input index is 1 (not 0)
    index--;
    if (index >= this.length) return Number.POSITIVE_INFINITY
    if (index < 0) return Number.NEGATIVE_INFINITY
    return this[index]
  }
  
  // helper function to find the k-th minimum element of two arrays
  function kthMin(arr1, arr2, k) {
    // length of arr1 is at least 3
    var left = 0
      , right = arr1.length + 1
      , x
    
    while (left <= right) {
      x = (right + left) >> 1
      if (nums1.get(x) > nums2.get(k-x+1)) right = x - 1;
      else if (nums1.get(x+1) < nums2.get(k-x)) left = x + 1;
      else return Math.max(nums1.get(x), nums2.get(k-x))
    }
  }
  
  k = (m + n + 1) >> 1
  
  if ((m + n) % 2) return kthMin(nums1, nums2, k)
  return (kthMin(nums1, nums2, k) + kthMin(nums1, nums2, k + 1)) / 2
}