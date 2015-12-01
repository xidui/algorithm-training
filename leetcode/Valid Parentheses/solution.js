/**********
 * Valid Parentheses
 * https://leetcode.com/problems/valid-parentheses/
 * @author: Jerry Zou
 * @email: jerry.zry@outlook.com
 * 
 * Runtime: 156ms | 2015.12.1 15:42 GMT+08
 * Beats 26.47% JS submissions
 */

/**
 * @param {string} s
 * @return {boolean}
 */
var isValid = function(s) {
  'use strict'
  
  let len = s.length
    , stack = []
  const OPEN = [ '(', '[', '{' ]
    , CLOSE = [ ')', ']', '}' ]
  
  for (let i = 0; i < len; ++i) {
    let char = s[i]
    if (OPEN.indexOf(char) >= 0) {
      stack.push(char)
    } else {
      if (stack.length == 0) return false
      let open = stack.pop()
      if (OPEN.indexOf(open) != CLOSE.indexOf(char)) {
        return false
      }
    }
  }
  
  if (stack.length > 0) return false
  
  return true
}