class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int pos[128];
        memset(pos, -1, sizeof(pos));
        int start = 0, ret = 0;
        for (int i = 0; i < s.length(); ++i){
            char c = s[i];
            if (pos[c] == -1 || pos[c] < start){
                pos[c] = i;
                continue;
            }
            ret = max(ret, i - start);
            start = pos[c] + 1;
            pos[c] = i;
        }
        ret = max(ret, (int)s.length() - start);
        return ret;
    }
};
