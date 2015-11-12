// 268ms O(m * n) + O(1)
// dynamic programming
class NumMatrix {
public:
    int **dp;

    NumMatrix(vector<vector<int>> &matrix) {
        int row = matrix.size();
        if (row == 0) return;
        int col = matrix[0].size();
        dp = new int*[row + 1];
        for (int i = 0; i <= row; ++i){
            dp[i] = new int[col + 1];
            memset(dp[i], 0, sizeof(dp[i]));
        }
        for (int i = 0; i < row; ++i){
            for (int j = 0; j < col; ++j){
                dp[i + 1][j + 1] = dp[i][j + 1] + dp[i + 1][j] - dp[i][j] + matrix[i][j];
            }
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        return dp[row2 + 1][col2 + 1] + dp[row1][col1] - dp[row2 + 1][col1] - dp[row1][col2 + 1];
    }
};