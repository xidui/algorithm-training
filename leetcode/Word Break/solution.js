// using dynamic programming
// f(n) = f(0, i) && f(i, j) && f(j, n)
// and the new ES6 feature: `set`
// 140ms

/**
 * @param {string} s
 * @param {set<string>} wordDict
 * @return {boolean}
 */
var wordBreak = function(s, wordDict) {
    var dp = [true];
    var len = s.length;
    if(wordDict.size===0||len===0) return false;
    for(var i=1; i<=len; i++){
        for(var j=0;j<i;j++){
            if( dp[j]&&wordDict.has(s.substring(j, i)) ){
                dp[i] = true;
                break;
            }
        }
        
    }
    return dp[len]||false;
};

/* test case
＊ var set = new Set();
＊ set.add("leet");
＊ set.add("code");
＊ wordBreak("leetcode", set);
*/