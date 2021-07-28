/*
     dp[i][j][k]:第i天结束时，持仓为j,交易次数为k的最大收益
*/
class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        prices.insert(prices.begin(), 0);
        //注意f数组初始化
        vector<vector<vector<int>>> f(n + 1, vector<vector<int>>(2, vector<int>(k + 1, -1000000000)));
        f[0][0][0] = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= 1; j++) {
                for (int c = 0; c <= k; c++) {
                    //什么也不做
                    f[i][j][c] = f[i - 1][j][c];
                    if (j == 0) {
                        //卖出股票
                        f[i][0][c] = max(f[i][0][c], f[i - 1][1][c] + prices[i]);
                    }
                    else if (j == 1 && c > 0) {
                        //买入股票
                        f[i][1][c] = max(f[i][1][c], f[i - 1][0][c - 1] - prices[i]);
                    }
                }
            }
        }
        //遍历最后一天结束时的所有交易次数所获得的收益的最大值
        int ans = 0;
        for (int c = 0; c <= k; c++) {
            ans = max(ans, f[n][0][c]);
        }
        return ans;
    }
};