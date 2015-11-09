/**********
 * Solution of Roman to Integer
 * https://leetcode.com/problems/roman-to-integer/
 * @author: Jerry Zou
 * @email: jerry.zry@outlook.com
 * 
 * Runtime: 360ms
 * Beats 75.58% JS submissions
 */

/**
 * @param {string} s
 * @return {number}
 */
var romanToInt = function(s) {

  var result = 0
    , stack = []
    , currentValue = 0
    , value = {
      'I': 1,
      'V': 5,
      'X': 10,
      'L': 50,
      'C': 100,
      'D': 500,
      'M': 1000
    }

  for (var i = 0; i < s.length; ++i) {
    currentValue = value[s[i]]
    // not I,V,X,L,C,D or M
    if (!currentValue) return false;
    if (!stack.length) { 
      stack.push(currentValue)
    } else {
      // invalid
      if (currentValue / stack[stack.length - 1] > 10) return false;
      
      // like IX, IIX
      if (currentValue > stack[stack.length - 1]) {
        while (stack.length > 0) {
          result -= stack.pop()
        }
        stack.push(currentValue)
      }
      // like IIX, XXI
      else if (currentValue == stack[stack.length - 1]) {
        stack.push(currentValue)
      }
      // like XI, XXI
      else {
        while (stack.length > 0) {
          result += stack.pop()
        }
        stack.push(currentValue)
      }
    }
  }

  while (stack.length > 0) {
    result += stack.pop()
  }

  return result
}