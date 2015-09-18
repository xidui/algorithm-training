class Solution {
public:
    // 68ms O(log n) complexity
    bool isPalindrome(int x) {
        if (x < 0) return false;
        if (x < 10) return true;
        int cmp = 1000000000;
        while (x / cmp == 0) cmp /= 10;
        while (cmp > 1){
            if (x / cmp != x % 10) return false;
            x -= x / cmp * (cmp + 1);
            x /= 10;
            cmp /= 100;
        }
        return true;
    }
};