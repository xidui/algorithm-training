/**
 * @param {number[]} nums
 * @return {number}
 */

 // 112ms - 98.51%
var rob = function(nums) {
    var dp = [];
    var len = nums.length;
    if(len===0) return 0;
    if(len<3){
        return Math.max.apply(null,nums)
    }
    dp[0]=nums[0];
    dp[1]=Math.max(nums[0], nums[1])
    for(var i=2;i<len;i++){
        dp[i] = Math.max(dp[i-2]+nums[i], dp[i-1]);
    }
    return dp[len-1];
};