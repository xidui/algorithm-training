
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