/****
 * Solution of https://leetcode.com/problems/palindrome-number/
 * @author: Jerry Zou
 * @date: 2015.8.16
 **/

/**
 * @param {number} x
 * @return {boolean}
 */

// Runtime: 748ms
var isPalindrome = function(x) {
    var str = x.toString(),
        len = Math.floor(str.length / 2)

    for (var i = 0; i < len; i++ ) {
        if (str[i] != str[str.length - i - 1]) {
            return false
        }
    }

    return true
}