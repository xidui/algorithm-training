
/*
* 196ms solution
* m/n = e^(ln(m) - ln(n))
*/

/**
 * @param {number} dividend
 * @param {number} divisor
 * @return {number}
 */
var divide = function(dividend, divisor) {
    if(divisor === 1){
        return dividend;
    }
    //get the sign of two numbers and abs them
    var flag1=(dividend<0), flag2=(divisor<0);
    dividend = Math.abs(dividend);
    divisor = Math.abs(divisor);

    //zero condition
    if(dividend === 0 || dividend < divisor){
        return 0;
    }

    //equal condition
    if(dividend === divisor){
        return (flag1^flag2)?-1:1;
    }

    //overflow condition
    var result = parseInt(Math.exp(Math.log(dividend)-Math.log(divisor)));
    if(result< -2147483648){
        return -2147483648;
    } else if(result > 2147483647){
        return 2147483647;
    }else{
        return (flag1^flag2)?-result:result;
    }
};


/**********
 * Anothor Solution to `Divide Two Integers`
 * https://leetcode.com/problems/divide-two-integers/
 * @author: Jerry Zou
 * @email: jerry.zry@outlook.com
 * 
 * Runtime: 228ms | 2015.12.19 00:10 GMT+08
 * Beats 80.00% JS submissions
 */

var divide = function(dividend, divisor) {
  'use strict'
	
	const INT_MAX = 2147483647
		, INT_MIN = -2147483648
	
	if (divisor === 0) return 0
	if (dividend > INT_MAX ||
			dividend < INT_MIN ||
			(dividend == INT_MIN && divisor == -1)) return INT_MAX		
	if (divisor === 1) return dividend
	if (divisor === -1) return -dividend
	
	let times = 1
		, result = 0
		, isPositive = (dividend > 0 && divisor > 0) || (dividend < 0 && divisor < 0)
	
	dividend = Math.abs(dividend)
	divisor = Math.abs(divisor)
	
	if (dividend < divisor) return 0
	
	while (dividend >= divisor) {
		if (divisor >= 1073741824) {
			result += times
			dividend -= divisor
		} else {
		  divisor = divisor << 1
			times = times << 1
		}
	}
	
	while (dividend < divisor) {
		divisor = divisor >> 1
		times = times >> 1
		if (dividend === divisor) {
			result += times
			break
		} else if (dividend > divisor) {
			dividend -= divisor
			result += times
		}
		if (times === 1) break
	}
	
	result = isPositive ? result : -result
	return result
}