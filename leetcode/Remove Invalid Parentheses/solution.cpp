// bad solution
// 412ms, too slow
class Solution {
public:
    class Compose{
    public:
        Compose(int total, int choose):t(total),c(choose){
            vec = new int[c];
            for (int i = 0; i < c; ++i) vec[i] = i;
        }

        bool next(){
            int i = c - 1; bool flag = false;
            for (; i >= 0; --i){
                if (vec[i] + c - i == t) continue;
                break;
            }
            if (i == -1) for (i = 0; i < c; ++i) vec[i] = i;
            else {
                flag = true;
                ++vec[i++];
                for (; i < c; ++i) vec[i] = vec[i - 1] + 1;
            }
            return flag;
        };

        int t, c;
        int *vec;
    };

    vector<string> removeInvalidParentheses(string s) {
        stack<char> sc;
        vector<int> left, right;
        int left_remove = 0, right_remove = 0;
        for (int i = 0; i < s.length(); ++i){
            if (s[i] == '(') {
                left.push_back(i);
                sc.push(s[i]);
            }else if (s[i] == ')'){
                right.push_back(i);
                if (sc.size()){
                    sc.pop();
                }else ++right_remove;
            }
        }
        left_remove = (int)sc.size();

        Compose a((int)left.size(), left_remove);
        Compose b((int)right.size(), right_remove);

        unordered_set<string> ss;
        do {
            do {
                unordered_set<int> sii;
                for (int i = 0; i < left_remove ; ++i) sii.insert(left[a.vec[i]]);
                for (int i = 0; i < right_remove; ++i) sii.insert(right[b.vec[i]]);

                string temp = "";
                int count = 0; bool flag = true;
                for (int i = 0; i < s.length(); ++i){
                    if (sii.find(i) != sii.end()) continue;
                    if (s[i] == '(') ++count;
                    else if (s[i] == ')') --count;
                    if (count < 0) {
                        flag = false;
                        break;
                    }
                    temp += s[i];
                }
                if (flag) ss.insert(temp);
            } while (b.next());
        } while (a.next());

        return vector<string>(ss.begin(), ss.end());
    }
};