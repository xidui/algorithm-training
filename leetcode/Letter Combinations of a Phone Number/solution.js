/**
 * @param {string} digits
 * @return {string[]}
 */

// I think this is an O(n^3) solution, but still runs faster than 100% submissions
var letterCombinations = function(digits) {
    var result = [];
        var table = {
        "1": [],
        "2": ['a', 'b', 'c'],
        "3": ['d', 'e', 'f'],
        "4": ['g', 'h', 'i'],
        "5": ['j', 'k', 'l'],
        "6": ['m', 'n', 'o'],
        "7": ['p', 'q', 'r', 's'],
        "8": ['t', 'u', 'v'],
        "9": ['w', 'x', 'y', 'z'],
        "*": [],
        "0": [],
        "#": []
    }
    digits.toString().split('').forEach(function(digit){

        var chars = table[digit]
        if(digit==='*'||digit==='0'||digit==='#'){
            // Empty block, because forEach doesn't support `break`
            // Adding this block will speed 136ms(20%) to 112ms(100%)
        }else{
            if(result.length === 0){
                result = result.concat(chars)
            }else{
                var len = chars.length
                var len_orig = result.length
                var t = result

                // Extends the array to target length
                for(var i=1;i<len;i++){
                    result = result.concat(t)
                }

                // Loops over whole array
                for(var i=0; i<len_orig; i++){
                    for(var j=0; j<len; j++){
                        result[i+j*len_orig] = result[i+j*len_orig] + chars[j]
                    }
                }

            }
        }
    })
    return result
};