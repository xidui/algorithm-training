/**********
 * Solution of ZigZag Conversion
 * https://leetcode.com/problems/zigzag-conversion/
 * @author: Jerry Zou
 * @email: jerry.zry@outlook.com
 * 
 * Runtime: 196ms
 * Beats 96.00% JS submissions
 */

/**
 * @param {string} s
 * @param {number} numRows
 * @return {string}
 */
var convert = function(s, numRows) {
  if (numRows == 1 || s.length <= numRows) return s

  var zzStr = []
    , i
    , j
    , totalGap = 2 * numRows - 2
    , currentGap

  for (i = 0; i < numRows; ++i) {
    j = i
    currentGap = totalGap - 2 * i
    while (j < s.length) {
      zzStr.push(s[j])
      if (currentGap == 0) currentGap = totalGap
      j += currentGap
      currentGap = totalGap - currentGap
    }
  }

  return zzStr.join('')
}