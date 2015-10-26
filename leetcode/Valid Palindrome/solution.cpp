// 12ms solution is fast enough
// but it is too long!
class Solution {
public:
    bool is(char c){
        return (c <= 90 && c >=65) || (c <= 122 && c >= 97) || (c <= 57 && c >= 48);
    }

    bool isNum(char c){
        return c <= 57 && c >= 48;
    }

    bool same(char a, char b){
        if (isNum(a) && isNum(b)) return a == b;
        if (!isNum(a) && !isNum(b)) return a == b + 32 || a == b - 32 || a == b;
        return false;
    }

    bool isPalindrome(string s) {
        if (s.length() == 0) return true;
        int f = 0, e = s.length() - 1;
        while (f < e){
            while (f < e && !is(s[f])) f++;
            while (f < e && !is(s[e])) e--;
            if (f < e && !same(s[f], s[e])) return false;
            ++f;--e;
        }
        return true;
    }
};

// this solution is what I want
// isalnum() and toupper() function
// remember them!
class Solution {
public:
    bool isPalindrome(string s) {
        for (int i = 0, j = s.size() - 1; i < j; i++, j--) { // Move 2 pointers from each end until they collide
            while (isalnum(s[i]) == false && i < j) i++; // Increment left pointer if not alphanumeric
            while (isalnum(s[j]) == false && i < j) j--; // Decrement right pointer if no alphanumeric
            if (toupper(s[i]) != toupper(s[j])) return false; // Exit and return error if not match
        }
        return true;
    }
};