// 64ms solution
// just so so
class Solution {
public:
    class TireNode{
    public:
        TireNode(string p):prefix(p){
            memset(next, 0, sizeof(next));
        };
        bool isEnd = false;
        TireNode* next[26];
        string prefix;
    };

    class Tire{
    public:
        Tire(){
            root = new TireNode("");
        }

        void addString(string s){
            TireNode *cur = root;
            string prefix = "";
            for (auto c : s){
                prefix += c;
                if (cur->next[c - 'a'] == NULL)
                    cur->next[c - 'a'] = new TireNode(prefix);
                cur = cur->next[c - 'a'];
            }
            cur->isEnd = true;
        }

        TireNode *root;
    };

    void dfs(vector<vector<char>>& board, int x, int y, TireNode* cur, vector<string>& ret){
        if (x < 0 || x >= board.size()) return;
        if (y < 0 || y >= board[0].size()) return;
        if (board[x][y] == '*') return;
        char c = board[x][y];
        if (cur == NULL || cur->next[c - 'a'] == NULL) return;
        if (cur->next[c - 'a']->isEnd){
            cur->next[c - 'a']->isEnd = false;
            ret.push_back(cur->next[c - 'a']->prefix);
        }
        board[x][y] = '*';
        dfs(board, x + 1, y, cur->next[c - 'a'], ret);
        dfs(board, x - 1, y, cur->next[c - 'a'], ret);
        dfs(board, x, y + 1, cur->next[c - 'a'], ret);
        dfs(board, x, y - 1, cur->next[c - 'a'], ret);
        board[x][y] = c;
    };

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        vector<string> ret;
        if (board.size() == 0 || board[0].size() == 0) return ret;

        Tire tire = Tire();
        for (auto s : words){
            tire.addString(s);
        }

        for (int i = 0; i < board.size(); ++i){
            for (int j = 0; j < board[0].size(); ++j){
                dfs(board, i, j, tire.root, ret);
            }
        }

        return ret;
    }
};