/**********
 * Solution of Longest Palindromic Substring
 * https://leetcode.com/problems/longest-palindromic-substring/
 * @author: Jerry Zou
 * @email: jerry.zry@outlook.com
 * 
 * Runtime: 132ms
 * Beats 100% JS submissions
 * Notes: If the input string contains `$` or `#`, you should change them to 
 *        some other characters that will be never in the string.
 */

/**
 * @param {string} s
 * @return {string}
 */

var longestPalindrome = function(s) {
  
  // Manacher's Algorithm
  
  // Justify if {string} s is totally palindrome string
  var i
    , len = Math.floor(s.length / 2) + 1
    , isTotalPalindrome = true

  for (i = 0; i < len; i++) {
      if (s[i] != s[s.length - i - 1]) {
          isTotalPalindrome = false
          break;
      }
  }
  
  if (isTotalPalindrome) return s;
  
  // preprocess, make {string} s must contain a palindrome of odd length
  s = [].join.call(s, '#')
  s = '$#' + s + '#$'

  var p = []
    , C = 1
    , R = 1
    , iMirror
    , max = 0
    , maxIndex
  
  for (i = 1; i < s.length - 1; i++) {
    iMirror = 2 * C - i
    p[i] = (R > i) ? Math.min(R - i, p[iMirror]) : 1

    while (s[i - p[i]] == s[i + p[i]]) p[i]++

    if (i + p[i] > R) {
      R = i + p[i]
      C = i
    }

    if (p[i] > max) {
      max = p[i]
      maxIndex = i
    }
  }

  return s.substr(maxIndex - max + 1, 2 * max - 1).replace(/[$#]/g, '')
}