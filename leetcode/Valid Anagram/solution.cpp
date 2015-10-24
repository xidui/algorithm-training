// hash table solution
// 64ms
class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) return false;
        unordered_map<char, int> table;
        for (int i = 0; i < s.length(); ++i) table[s[i]]++;
        for (int i = 0; i < t.length(); ++i){
            if (table.find(t[i]) == table.end()) return false;
            if (table[t[i]] == 0) return false;
            table[t[i]]--;
        }
        return true;
    }
};