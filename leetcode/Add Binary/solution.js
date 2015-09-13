/**
 * @param {string} a
 * @param {string} b
 * @return {string}
 */

 //Basic Solution - 160ms
var addBinary = function(a, b) {

	String.prototype.reverse = function(){
		return this.split('').reverse().toString().replace(/,/g,"")
	}

	// A function that add three binary number
	// I'm sure the transform cost a lot time
	var add = function(m, n, o){
		return (parseInt(m, 2) + parseInt(n, 2) + parseInt(o, 2)).toString(2)
	}

	var lena = a.length, lenb = b.length
	var diff = Math.abs(lena-lenb)
	var len = Math.max(lena, lenb)
	var left = lena>lenb?a:b
	var right = lena>lenb?b:a
	var res = ""
	var bonus = "0"

	// Adding this statement will speed 176ms up to 160ms
	if(lena*lenb===1){
		return add(left, right, "0")
	}

	// Scan both array based on the greater length
	for(var i = len-1; i>=0; i--){
		var p = left[i] || "0", q = right[i-diff] || "0"
		var t = add(p, q, bonus)
		if(t.length>1){
			bonus = "1"
			t = t[1]
		} else {
			bonus = "0"
		}

		// And store the result
		res += t
	}
	if(bonus==="1"){
		res += "1"
	}

	// then reverse it back
	return res.reverse()
};
