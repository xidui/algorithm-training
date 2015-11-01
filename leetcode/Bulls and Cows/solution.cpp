// 20ms solution
class Solution {
public:
    string getHint(string secret, string guess) {
        unordered_map<char, int> mci;
        int A = 0, B = 0;
        for (int i = 0; i < secret.length(); ++i){
            if (secret[i] == guess[i]){
                ++A;
                continue;
            }
            if (++mci[secret[i]] <= 0) ++B;
            if (--mci[guess[i]] >= 0) ++B;
        }
        return to_string(A) + "A" + to_string(B) + "B";
    }
};

// 4ms solution
class Solution {
public:
    string getHint(string secret, string guess) {
        int a = 0, b = 0, c[99] = {}, i = 0, g;
        for (int s : secret) {
            a += s == (g = guess[i++]);
            b += (c[s]++ < 0) + (c[g]-- > 0);
        }
        return to_string(a) + "A" + to_string(b - a) + "B";
    }
};