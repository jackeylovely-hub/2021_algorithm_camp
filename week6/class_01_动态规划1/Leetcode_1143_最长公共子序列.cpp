/*
    动态规划：将人工模拟需要哪些信息，放进动归的数组当中；
    打印方案：不存储具体的方案数，只存储路径
*/
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.length();
        int n = text2.length();
        text1 = " " + text1;
        text2 = " " + text2;
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        vector<vector<int>> dir(m + 1, vector<int>(n + 1, 0));
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (text1[i] == text2[j]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                    dir[i][j] = 0;
                }
                else if (dp[i - 1][j] >= dp[i][j - 1]) {
                    dp[i][j] = dp[i - 1][j];
                    dir[i][j] = 1;
                }
                else {
                    dp[i][j] = dp[i][j - 1];
                    dir[i][j] = 2;
                }
            }
        }
        print(text1, dir, m, n);
        cout << ans << endl;
        return dp[m][n];
    }
private:
    void print(string& text1, vector<vector<int>>& dir, int i, int j) {
        //递归终止条件
        if (i == 0 || j == 0) return;
        if (dir[i][j] == 0) {
            print(text1, dir, i - 1, j - 1);
            ans.push_back(text1[i]);
        }
        else if (dir[i][j] == 1) {
            print(text1, dir, i - 1, j);
        }
        else {
            print(text1, dir, i, j - 1);
        }
    }
    string ans;
};