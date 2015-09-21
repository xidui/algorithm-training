/**
 * @param {number} n
 * @return {number}
 */
var climbStairs = function(n) {
    var dp = [1,1,2];
    for(var i=3;i<50;i++) dp[i]=dp[i-1]+dp[i-2];
    return dp[n];
};