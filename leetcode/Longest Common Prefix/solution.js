/**
 * @param {string[]} strs
 * @return {string}
 */
var longestCommonPrefix = function(strs) {
	if (strs.length == 0) return ""
	if (strs.length == 1) return strs[1]
	
  var len = strs.length
    , i = 1
    , j = 0
    , current

  while (j < len) {
    current = strs[0][j]
    while (i < len) {
      if (current != strs[i][j]) return strs[0].substr(0, j)
    }
    j++
    i = 1
  }
}