// fastest solution with hashmap
// 0.12ms
// description is at https://leetcode.com/discuss/70923/12-line-of-c-code-o-n-00012s-execution-time-3-solutions-inside
class Solution {
public:
    int cycle(vector<int>& citations){
        // there are 'flag' nums greater than 'ret + 1'
        int ret = 0, flag = 0, size = citations.size();
        int record[size + 1];
        memset(record, 0, sizeof(record));
        for (int i = 0; i < size; ++i){
            int cur = citations[i];
            if (cur >= size) record[size]++;
            else record[cur] += 1;
            if (cur <= ret) continue;
            if (++flag < ret + 1) continue;
            flag -= record[++ret];
        }
        return ret;
    }

    int hIndex(vector<int>& citations) {
        for (int i = 0; i < 99; ++i) cycle(citations);
        return cycle(citations);
    }
};

// second solution is the same with first
// but i use unordered_map
// 2.56ms
class Solution {
public:
    int cycle(vector<int>& citations){
        // there are 'flag' nums greater than 'ret + 1'
        int ret = 0, flag = 0;
        unordered_map<int, int> uii;
        for (int i = 0; i < citations.size(); ++i){
            int cur = citations[i];
            uii[cur] += 1;
            if (cur <= ret) continue;
            if (++flag >= ret + 1){
                ++ret;
                flag -= uii[ret];
            }
        }
        return ret;
    }

    int hIndex(vector<int>& citations) {
        for (int i = 0; i < 99; ++i) cycle(citations);
        return cycle(citations);
    }
};

// third solution with sort
// 1.08ms
class Solution {
public:
    int cycle(vector<int>& citations){
        sort(citations.begin(), citations.end());
        int i = citations.size() - 1;
        for (; i >= 0; --i){
            int c = citations.size() - i;
            if (citations[i] < c) break;
        }
        return citations.size() - 1 -i;
    }

    int hIndex(vector<int>& citations) {
        for (int i = 0; i < 99; ++i) cycle(citations);
        return cycle(citations);
    }
};