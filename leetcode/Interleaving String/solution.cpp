// dynamic programming with map
// actually i think this method is better than the second
// because it avoided plenty of unnecessary computing while the second not
// but i don't understand why this is a bit slower
// 2.84ms
class Solution {
public:
    bool cycle(string s1, string s2, string s3){
        if (s1.length() + s2.length() != s3.length()) return false;
        if (s1.length() == 0) return s2 == s3;
        if (s2.length() == 0) return s1 == s3;
        unordered_map<int, int> mii;
        mii[0] = 0;
        for (int i = 1; i <= s3.length(); ++i){
            unordered_map<int, int> mii_temp;
            for (unordered_map<int, int>::iterator it = mii.begin(); it != mii.end(); ++it){
                int a = it->first;
                int b = it->second;
                if (a + 1 <= s1.length() && s1[a] == s3[i - 1]) mii_temp[a + 1] = b;
                if (b + 1 <= s2.length() && s2[b] == s3[i - 1]) mii_temp[a] = b + 1;
            }
            mii = mii_temp;
            if (i == s3.length() && mii.size() != 0) return true;
        }
        return false;
    }

    bool isInterleave(string s1, string s2, string s3) {
        for (int i = 0; i < 99; ++i){
            cycle(s1, s2, s3);
        }
        return cycle(s1, s2, s3);
    }
};

// dynamic programming with array
// 1.36ms
class Solution {
public:
    bool cycle(string s1, string s2, string s3){
        if (s1.length() + s2.length() != s3.length()) return false;
        if (s1.length() == 0) return s2 == s3;
        if (s2.length() == 0) return s1 == s3;
        int dp[s3.length() + 1][s3.length() + 1];
        memset(dp, 0, sizeof(dp));
        dp[0][0] = 1;
        for (int i = 1; i <= s3.length(); ++i){
            bool flag = false;
            for (int j = 0; j <= i && j <= s1.length(); ++j){
                if (i - j > s2.length()) continue;
                // s1: j, s2: i - j
                dp[i][j] = (i - j > 0 && dp[i - 1][j] && s3[i - 1] == s2[i - j - 1])
                || (j > 0 && dp[i - 1][j - 1] && s3[i - 1] == s1[j - 1]);
                if (dp[i][j]) flag = true;
            }
            if (i == s3.length() && flag) return true;
        }
        return false;
    }

    bool isInterleave(string s1, string s2, string s3) {
        for (int i = 0; i < 99; ++i){
            cycle(s1, s2, s3);
        }
        return cycle(s1, s2, s3);
    }
};

// dynamic programming
// 12 ms
// but the code is more readable
class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int n1 = s1.size();
        int n2 = s2.size();
        if(n1+n2 != s3.size()) return false;
        vector<vector<bool> > f(n1+1, vector<bool>(n2+1, false));
        f[0][0] = true;
        for(int i = 0; i <= n1; ++i)
        {
            for(int j = 0; j <= n2; ++j)
            {
                int len = i+j;
                if(i >= 1 && s1[i-1] == s3[len-1]) f[i][j] = f[i][j] || f[i-1][j];
                if(j >= 1 && s2[j-1] == s3[len-1]) f[i][j] = f[i][j] || f[i][j-1];
            }
        }
        return f[n1][n2];
    }
};