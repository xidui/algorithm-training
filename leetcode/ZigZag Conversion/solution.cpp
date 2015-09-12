class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) return s;
        string ret;
        int step = 2 * numRows - 2;
        for (int i = 0; i< numRows; ++i){
            for (int j = i; j < s.length(); j += step){
                ret += s[j];
                if (i == 0 || i == numRows - 1) continue;
                int next = j + step - (j % step) * 2;
                if (next < s.length()) ret += s[next];
            }
        }
        return ret;
    }
};