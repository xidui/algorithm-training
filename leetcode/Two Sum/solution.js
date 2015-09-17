        
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
