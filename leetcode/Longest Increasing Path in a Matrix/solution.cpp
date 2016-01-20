// 88ms
// dfs,dp
class Solution {
public:
    int** m;

    int dfs(int i, int j, vector<vector<int>>& matrix){
        if (m[i][j] > 0) return m[i][j];
        int dx[4] = {0, 1, 0, -1};
        int dy[4] = {1, 0, -1, 0};
        m[i][j] = 1;
        for (int k = 0; k < 4; ++k){
            if (i + dx[k] < 0 || i + dx[k] >= matrix.size()) continue;
            if (j + dy[k] < 0 || j + dy[k] >= matrix[0].size()) continue;
            if (matrix[i + dx[k]][j + dy[k]] > matrix[i][j]) {
                m[i][j] = max(m[i][j], dfs(i + dx[k], j + dy[k], matrix) + 1);
            }
        }
        return m[i][j];
    }

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        m = new int*[matrix.size()];
        for (int i = 0; i < matrix.size(); ++i){
            m[i] = new int[matrix[0].size()];
            memset(m[i], 0, sizeof(int) * matrix[0].size());
        }

        int ret = 0;
        for (int i = 0; i < matrix.size(); ++i){
            for (int j = 0; j < matrix[0].size(); ++j){
                ret = max(ret, dfs(i, j, matrix));
            }
        }
        return ret;
    }
};