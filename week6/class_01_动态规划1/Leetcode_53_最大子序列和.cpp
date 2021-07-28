/*
    dp[i][j]:从起点走到(i,j)的方案数为dp[i][j];
*/
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        dp = vector<vector<int>>(m, vector<int>(n, 0));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0 && j == 0) {
                    if (obstacleGrid[i][j] == 1) dp[i][j] = 0;
                    else dp[i][j] = 1;
                }
                else if (obstacleGrid[i][j] == 1) dp[i][j] = 0;
                else if (i == 0) dp[i][j] = dp[i][j - 1];
                else if (j == 0) dp[i][j] = dp[i - 1][j];
                else dp[i][j] = dp[i][j - 1] + dp[i - 1][j];
            }
        }
        return dp[m - 1][n - 1];
    }
private:
    vector<vector<int>> dp;
};