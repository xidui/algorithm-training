/**********
 * Solution of Longest Common Prefix
 * https://leetcode.com/problems/longest-common-prefix/
 * @author: Jerry Zou
 * @email: jerry.zry@outlook.com
 * 
 * Runtime: 148ms
 * Beats 13.79% JS submissions
 */

/**
 * @param {string[]} strs
 * @return {string}
 */
var longestCommonPrefix = function(strs) {
  if (strs.length == 0) return ""
  if (strs.length == 1) return strs[0]
  
  strs.sort()
	
  var first = strs[0]
    , last = strs[strs.length - 1]
    , i = 0
    , len = first.length
  
  for (; i < len; ++i) {
    if (first[i] != last[i]) return strs[0].substr(0, i)
  }
  
  return strs[0]
}