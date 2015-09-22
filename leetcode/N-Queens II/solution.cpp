class Solution {
public:
    // similar with problem 51
    int totalNQueens(int n) {
        int pos[n], ptr = 0;
        memset(pos, 0, sizeof(pos));
        int count = 0;
        string s = "";
        for (int i = 0; i < n; ++i) s += '.';
        while (ptr != -1) {
            if (ptr == n){
                count++;
                pos[--ptr]++;
                continue;
            }
            if (pos[ptr] == n) {
                pos[ptr] = 0;
                pos[--ptr]++;
                continue;
            }
            bool flag = true;
            for (int j = 0; j < ptr; ++j) {
                if (pos[j] == pos[ptr] || abs(pos[j] - pos[ptr]) == ptr - j) {
                    flag = false;
                    break;
                }
            }
            if (flag) {
                ++ptr;
                if (ptr < n) pos[ptr] = 0;
                continue;
            }
            pos[ptr]++;
        }
        return count;
    }
};