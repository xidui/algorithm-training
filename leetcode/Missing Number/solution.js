
/**
* #268 Missing Number
* This Problem is simple enough for a Medium
*
* I tried several ways to make it runs faster
* In a word, `while` and `forEach` performs better than `for`
* Still, the solution runs slower than 16% people
* How did they optimized
*/

/* implements in while － 136ms */
/**
 * @param {number[]} nums
 * @return {number}
 */
var missingNumber = function(nums) {
    var len = nums.length
    var i=len
    var res = 0
    while(i--){
        res+=nums[i]
    }
    
    return (len+len*len)/2 - res
};

/* implements in forEach － 136ms */
/**
 * @param {number[]} nums
 * @return {number}
 */
var missingNumber = function(nums) {
    var len = nums.length
    var res = 0
    nums.forEach(function(n, i){
        res+=n
    })
    return (len+len*len)/2 - res
};

/* implements in for － 148ms */
/**
 * @param {number[]} nums
 * @return {number}
 */
var missingNumber = function(nums) {
    var len = nums.length
    var res = 0
    for(var i=0;i<len;i++){
        res+=nums[i]
    }
    
    return (len+len*len)/2 - res
};

/* implements in reduce － 164ms */
/**
 * @param {number[]} nums
 * @return {number}
 */
var missingNumber = function(nums) {
    var len = nums.length
    return (len+len*len)/2 - nums.reduce(function(pv,cv){return pv+cv}, 0)
};