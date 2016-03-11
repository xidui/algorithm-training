// 0ms
class Solution {
public:
    bool isSelfCrossing(vector<int>& x) {
        if (x.size() < 4) return false;
        bool flag = true;
        for (int i = 2; i < x.size(); ++i){
            if (flag && x[i] <= x[i - 2]) {
                flag = false;
                // do some thing here
                if (i >= 3 && i + 1 < x.size() && x[i - 1] - x[i - 3] <= x[i + 1]) {
                    if ((i == 3 && x[i - 2] == x[i])
                        || x[i - 2] - x[i - 4] <= x[i] )
                        return true;
                }
            } else if (!flag && x[i] >= x[i - 2])
                return true;
        }
        return false;
    }
};