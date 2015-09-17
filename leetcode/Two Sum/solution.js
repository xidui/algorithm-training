        
/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number[]}
 */

/*
* 156ms
* O(n) time , O(n) space for init hash table
* O(nlgn) for sorting 
* O(n) for finding solution
*/
var twoSum = function(nums, target) {
    var len = nums.length;
    var result = [];
    var hash = {};
    var asc = function(a, b){
        return a-b;
    }

    // Hash handler with collision detect
    var setHash = function(key, value){
        if(hash[key]){
            if(!(hash[key] instanceof Array)){
                hash[key] = [hash[key]];
            }
            hash[key].push(value);
        }else{
            hash[key] = value;
        }
    }

    // Hash getter
    var getHash = function(key){
        if( hash[key] instanceof Array){
            return hash[key].splice(0,1)[0]
        } else {
            return hash[key]
        }
    }

    // Generate the hash table before sorting
    nums.forEach(function(n, i){
        setHash(n, i+1);
    })
    nums.sort(asc);
    for(var i=0, j=len-1;i!=j;){
        var sum = nums[i] + nums[j];
        // because the problem describes as only one answer will be found
        // so using two pointers scanning from begin and end
        if( sum === target){
            return ([getHash(nums[i]), getHash(nums[j])]).sort(asc);
        } else if(sum < target){
            i++
        } else{
            j--
        }
    }
    return result;
};

/****
 * @author: Jerry Zou
 * @date: 2015.6.4
 **/

// Runtime: 116ms

var twoSum = function(nums, target) {
    var i, j, num, hash = {};

    for (i = 0; i < nums.length; i++) {
        hash[nums[i]] = i + 1;
    }
    for (i = 0; i < nums.length; i++) {
        j = hash[target - nums[i]];
        if (j && j !== i + 1) {
            i = i + 1;
            return i < j ? [i, j] : [j, i];
        }
    }
    return [-1, -1];
};