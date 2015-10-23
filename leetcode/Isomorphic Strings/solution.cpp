// 44ms solution
// not the best
class Solution {
public:
    bool check(string s, string t){
        map<char, vector<int> > mcv;
        for (int i = 0; i < s.length(); ++i) mcv[s[i]].push_back(i);
        for (map<char, vector<int> >::iterator it = mcv.begin(); it != mcv.end(); ++it){
            if (it->second.size() == 1) continue;
            for (int j = 0; j < it->second.size() - 1; ++j){
                if (t[it->second[j]] != t[it->second[j + 1]]) return false;
            }
        }
        return true;
    }

    bool isIsomorphic(string s, string t) {
        return check(s, t) && check(t, s);
    }
};

// the solution given by others
// very excellent idea
// 8 ms
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int m1[256] = {0}, m2[256] = {0}, n = s.size();
        for (int i = 0; i < n; ++i) {
            if (m1[s[i]] != m2[t[i]]) return false;
            m1[s[i]] = i + 1;
            m2[t[i]] = i + 1;
        }
        return true;
    }
};