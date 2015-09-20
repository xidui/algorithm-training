class Solution {
public:
    bool isMatch(string s, string p) {
        int ls = s.length();
        int lp = p.length();
        bool mark[ls + 1][lp + 1];
        memset(mark,0,sizeof(mark)); 
        mark[0][0] = 1;
        for(int i = 1; i < lp && p[i] == '*'; i += 2){
            mark[0][i + 1] = 1;
        }
        for(int i = 1; i <= ls; ++i){
            for(int j = 1; j <= lp; ++j){
                if(p[j - 1] == '.' || p[j - 1] == s[i - 1])
                    mark[i][j] = mark[i - 1][j - 1];
                else if(j > 1 && p[j-1] == '*')
                    mark[i][j] = mark[i][j - 2] || (mark[i - 1][j] && (p[j - 2] == '.' || s[i - 1] == p[j - 2]));
            }
        }
        return mark[ls][lp];
    }
};