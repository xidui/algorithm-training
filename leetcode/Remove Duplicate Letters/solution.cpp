// 12ms
// not very good
class Solution {
public:
    string removeDuplicateLetters(string s) {
        int temp[s.length()];
        int c[26]; memset(c, 0, sizeof(c));
        for (int i = s.length() - 1; i >= 0; --i) temp[i] = c[s[i] - 'a']++;
        string ret = "";
        string stack = "";
        for (int i = 0; i < s.length(); ++i){
            if (c[s[i] - 'a'] == -1) continue;
            int j = stack.length() - 1;
            for (; j >= 0 && s[i] < stack[j]; --j);
            string flag = "";
            if (j < 0) stack = s[i];
            else {
                flag = stack.substr(j + 1, stack.size() - j - 1);
                stack = stack.substr(0, j + 1);
                if (s[i] != stack[j]){
                    stack = stack + s[i];
                }
            }
            if (temp[i] == 0){
                ret = ret + stack;
                for (int k = 0; k < stack.length(); ++k) {
                    c[stack[k] - 'a'] = -1;
                }
                if (s[i] == stack[j]) stack = flag;
                else stack = "";
            }else{
                if (s[i] == stack[j]) stack = stack + flag;
            }
        }
        return ret;
    }
};

// 4ms others solution
// the basic idea is almost the same with mine
// but my solution has more trivial logics
class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<unsigned int> cnt(26,0); //only consider lowercase letters
        vector<bool> inRes(26, false); //true if the letter has been added to res
        for(char ch:s) cnt[ ch-'a' ]++;
        string res = ""; //use res as a stack
        for(char ch:s){
           cnt[ ch-'a' ]--;
           if(res.empty()){
               res.push_back(ch);
               inRes[ ch-'a' ] = true;
               continue;
           }
           if(inRes[ch-'a']) continue;
           while(ch<res.back() && !res.empty() && cnt[ res.back()-'a' ]>0){
               inRes[ res.back()-'a' ] = false;
               res.pop_back();

           }
           res.push_back(ch);
           inRes[ ch-'a' ] = true;
        }
        return res;
    }
};