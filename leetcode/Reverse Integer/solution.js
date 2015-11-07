/**********
 * Solution of Reverse Integer
 * https://leetcode.com/problems/reverse-integer/
 * @author: Jerry Zou
 * @email: jerry.zry@outlook.com
 * 
 * Runtime: 184ms
 * Beats 86.61% JS submissions
 */

/**
 * @param {number} x
 * @return {number}
 */
var reverse = function(x) {
  var max = 2147483647
    , min = -2147483648
    
  if (x > max || x < min) return 0

  var result = 0

  while (x != 0) {
    result = result * 10 + x % 10
    x = (x / 10) << 0
  }

  return (result <= max && result >= min) ? result : 0
};