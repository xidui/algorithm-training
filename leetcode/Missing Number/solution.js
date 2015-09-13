
/**
* #268 Missing Number
* 其实是十分水一道题，但不知道为什么标记为Medium
* 题意是给出一组[1, n]的数，但是会挖去其中一个
* 求出挖去的是哪一个数
* 那么只要对输入的数组求和，再用SUM(1,n)减去所得的和即是缺少的数
*
* 但对JS不同的几种实现方式做了一些尝试
* 可见while和forEach性能都比for循环要高一些
* Array对象提供的reduce方法则性能一般
* 最后我做的136ms在js实现里排在前17% 不知道哪里还可以继续优化
*/

/* while版 － 136ms */
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

/* forEach版 － 136ms */
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

/* for版 － 148ms */
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

/* reduce一句话求和版 － 164ms */
/**
 * @param {number[]} nums
 * @return {number}
 */
var missingNumber = function(nums) {
	var len = nums.length
	return (len+len*len)/2 - nums.reduce(function(pv,cv){return pv+cv}, 0)
};