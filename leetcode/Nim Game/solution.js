/**********
 * Nim Game
 * https://leetcode.com/problems/nim-game/
 * @author: Jerry Zou
 * @email: jerry.zry@outlook.com
 * 
 * Runtime: 156ms | 2015.12.1 15:42 GMT+08
 * Beats 26.47% JS submissions
 */

/**
 * @param {number} n
 * @return {boolean}
 */

/**
 * Solution 1
 * Runtime: 156ms | 2016.1.5 19:28 GMT+08
 * Beats 45.38% JS submissions
 */
var canWinNim = function(n) {
  return n % 4 > 0
}

/**
 * Solution 2
 * Note: 
 * - Dynamic Programming which can solve similiar problem, e.g. pick 1,3,7 stones every turn
 * - Cannot pass all test cases because of `Memory Limit Exceeded`
 */
var canWinNim = (function() {
  'use strict'
  var results = [true, true, true, false]
  return function(n) {
    if (n <= results.length) return results[n - 1]
    for (let i = results.length; i < n; i++) {
      results.push( !results[i - 1] || !results[i - 2] || !results[i - 3] )
    }
    return results[n - 1]
  }
}())