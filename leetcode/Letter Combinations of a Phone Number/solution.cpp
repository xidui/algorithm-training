class Solution {
public:
    // ugly solution but is fast
    // only takes 0ms
    vector<string> letterCombinations(string digits) {
        map<char, vector<string> > mvc;
        mvc['2'].push_back("a");
        mvc['2'].push_back("b");
        mvc['2'].push_back("c");
        mvc['3'].push_back("d");
        mvc['3'].push_back("e");
        mvc['3'].push_back("f");
        mvc['4'].push_back("g");
        mvc['4'].push_back("h");
        mvc['4'].push_back("i");
        mvc['5'].push_back("j");
        mvc['5'].push_back("k");
        mvc['5'].push_back("l");
        mvc['6'].push_back("m");
        mvc['6'].push_back("n");
        mvc['6'].push_back("o");
        mvc['7'].push_back("p");
        mvc['7'].push_back("q");
        mvc['7'].push_back("r");
        mvc['7'].push_back("s");
        mvc['8'].push_back("t");
        mvc['8'].push_back("u");
        mvc['8'].push_back("v");
        mvc['9'].push_back("w");
        mvc['9'].push_back("x");
        mvc['9'].push_back("y");
        mvc['9'].push_back("z");

        vector<string> ret;
        for (int i = 0; i < mvc[digits[0]].size(); ++i){
            ret.push_back(mvc[digits[0]][i]);
        }
        for (int i = 1; i < digits.length(); ++i){
            int size = ret.size();
            for (int k = 0; k < size; ++k){
                for (int j = 0; j < mvc[digits[i]].size(); ++j){
                    ret.push_back(ret[0] + mvc[digits[i]][j]);
                }
                ret.erase(ret.begin());
            }
        }
        return ret;
    }
};