class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        prices.insert(prices.begin(), 0);
        vector<vector<vector<int>>> f(2 + 1, vector<vector<int>>(2, vector<int>(2, -10000000000)));
        f[0][0][0] = 0;
        //考虑所有的出边
        for (int i = 0; i < n; i++) {
            for (int j = 0; j <= 1; j++) {
                for (int d = 0; d <= 1; d++) {
                    //买
                    if (j == 0 && d == 0) {
                        f[i + 1 & 1][1][0] = max(f[i + 1 & 1][1][0], f[i & 1][j][d] - prices[i + 1]);
                    }
                    else if (j == 1 && d == 0) {
                        f[i + 1 & 1][0][1] = max(f[i + 1 & 1][0][1], f[i & 1][j][d] + prices[i + 1]);
                    }
                    f[i + 1 & 1][j][0] = max(f[i + 1 & 1][j][0], f[i & 1][j][d]);
                }
            }
        }
        int ans = 0;
        for (int d = 0; d <= 1; d++) {
            ans = max(ans, f[n & 1][0][d]);
        }
        return ans;
    }
};