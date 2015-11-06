// 0ms
// rather easy problem
class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        for (int i = 0; i < board.size(); ++i){
            for (int j = 0; j < board[0].size(); ++j){
                int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
                int dy[8] = {1, -1, 0, -1, 1, 0, 1, -1};
                int count = 0;
                for (int k = 0; k < 8; ++k){
                    int x = i + dx[k], y = j + dy[k];
                    if (x < 0 || x >= board.size() || y < 0 || y >= board[0].size())
                        continue;
                    if (k < 4 && board[x][y] / 2 == 1) ++count;
                    if (k >= 4 && board[x][y] == 1) ++count;
                    if (count > 3) break;
                }
                if (count < 2 || count > 3) board[i][j] *= 2;
                else{
                    board[i][j] *= 3;
                    if (count == 3 && board[i][j] == 0) board[i][j] += 1;
                }
            }
        }
        for (int i = 0; i < board.size(); ++i){
            for (int j = 0; j < board[0].size(); ++j){
                board[i][j] = board[i][j] % 2;
            }
        }
    }
};