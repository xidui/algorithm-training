// my first solution
// with unordered_map and vector
// 1680ms
class Solution {
public:
    int maxProduct(vector<string>& words) {
        vector<unordered_map<char, bool> > vuci;
        for (int i = 0; i < words.size(); ++i){
            unordered_map<char, bool> temp;
            for (int j = 0; j < words[i].length(); ++j){
                temp[words[i][j]] = true;
            }
            vuci.push_back(temp);
        }
        int ret = 0;
        for (int i = 1; i < words.size(); ++i){
            for (int j = i - 1; j >= 0; --j){
                bool flag = true;
                unordered_map<char, bool>::iterator it = vuci[i].begin();
                for (; it != vuci[i].end() && flag; ++it){
                    if (vuci[j][it->first]) flag = false;
                }
                if (flag) ret = max(ret, (int)words[i].length() * (int)words[j].length());
            }
        }
        return ret;
    }
};

// my second solution
// with array
// 344ms
class Solution {
public:
    int maxProduct(vector<string>& words) {
        bool mat[words.size()][26];
        memset(mat, 0, sizeof(mat));
        for (int i = 0; i < words.size(); ++i){
            for (auto c: words[i]) mat[i][c - 'a']  = true;
        }
        int ret = 0;
        for (int i = 1; i < words.size(); ++i){
            for (int j = 0; j < i; ++j){
                bool flag = true;
                for (int k = 0; k < 26 && flag; ++k){
                    flag = flag && (!mat[i][k] || !mat[j][k]);
                }
                if (flag) ret = max(ret, (int)words[i].length() * (int)words[j].length());
            }
        }
        return ret;
    }
};

// my last solution
// with bit manipulation
// 112ms
class Solution {
public:
    int maxProduct(vector<string>& words) {
        int v[words.size()], ret = 0;
        memset(v, 0, sizeof(v));
        for (int i = 0; i < words.size(); ++i){
            for (auto c: words[i]) v[i] |= 1 << (c - 'a');
            for (int j = 0; j < i; ++j){
                if ((v[i] & v[j]) == 0) ret = max(ret, (int)words[i].size() * (int)words[j].size());
            }
        }
        return ret;
    }
};