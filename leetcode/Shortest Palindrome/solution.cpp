// 76ms
// not the best solution
class Solution {
public:
    string shortestPalindrome(string s) {
        int pos = 0, start = pos, end;
        while (start < (s.length() + 1) / 2){
            end = start;
            int i = 0;
            while(s[start] == s[end] && start + end < s.length()) end++;
            while(start - i - 1 >= 0 && s[start - i - 1] == s[end + i]){
                ++i;
            }
            if (start - i - 1 >= 0){
                start = end + i;
                continue;
            }
            start = end;
            pos = end + i;
        }
        string ret = s;
        for (int i = pos; i < s.length(); ++i){
            ret = s[i] + ret;
        }
        return ret;
    }
};