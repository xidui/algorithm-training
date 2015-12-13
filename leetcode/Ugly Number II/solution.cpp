// 12ms dp solution
// can be generized to any nums of prime
// O(n * k)
class Solution {
public:
    int nthUglyNumber(int n) {
        int prime[3] = {2, 3, 5};
        int seq[n] = {}; seq[0] = 1;
        int ptr[3] = {0, 0, 0};
        for (int i = 1; i < n; ++i){
            seq[i] = INT32_MAX;
            for (int j = 0; j < 3; ++j){
                seq[i] = min(seq[i], seq[ptr[j]] * prime[j]);
            }
            for (int j = 0; j < 3; ++j){
                if (seq[i] == seq[ptr[j]] * prime[j]){
                    ptr[j]++;
                }
            }
        }
        return seq[n - 1];
    }
};

// 440ms
// solution with set
// O(n * k * log(n))
class Solution {
public:
    int nthUglyNumber(int n) {
        int prime[3] = {2, 3, 5};
        set<int> si; si.insert(1);
        for (int i = 1; i < n; ++i){
            int top = *si.begin();
            for (int j = 0; j < 3; ++j){
                if ((long)top * prime[j] > INT32_MAX) continue;
                si.insert(top * prime[j]);
            }
            si.erase(top);
        }
        return *si.begin();
    }
};