// 120ms dp solution
class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        int seq[n] = {}; seq[0] = 1;
        vector<int> ptr(primes.size(), 0);
        for (int i = 1; i < n; ++i){
            seq[i] = INT32_MAX;
            for (int j = 0; j < primes.size(); ++j){
                seq[i] = min(seq[i], seq[ptr[j]] * primes[j]);
            }
            for (int j = 0; j < primes.size(); ++j){
                if (seq[i] == seq[ptr[j]] * primes[j]){
                    ptr[j]++;
                }
            }
        }
        return seq[n - 1];
    }
};