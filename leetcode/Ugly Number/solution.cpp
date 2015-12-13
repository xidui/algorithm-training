class Solution {
public:
    bool isUgly(int num) {
        if (num == 0) return false;
        int prime[3] = {2, 3, 5};
        for (int i = 0; i < 3; ++i){
            while (num % prime[i] == 0) num /= prime[i];
        }
        return num == 1;
    }
};