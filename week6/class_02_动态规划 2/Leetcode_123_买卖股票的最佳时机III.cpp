class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        prices.insert(prices.begin(), 0);
        vector<vector<vector<int>>> f(2 + 1, vector<vector<int>>(2, vector<int>(2 + 1, -1000000000)));
        f[0][0][0] = 0;
        //debug nµÄ·¶Î§Îª1-n;
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= 1; j++) {
                for (int c = 0; c <= 2; c++) {
                    f[i & 1][j][c] = f[i - 1 & 1][j][c];
                    if (j == 0) {
                        f[i & 1][0][c] = max(f[i & 1][0][c], f[i - 1 & 1][1][c] + prices[i]);
                    }
                    else if (j == 1 && c > 0) {
                        f[i & 1][1][c] = max(f[i & 1][1][c], f[i - 1 & 1][0][c - 1] - prices[i]);
                    }
                }
            }
        }
        int ans = 0;
        for (int c = 0; c <= 2; c++) {
            //cout << f[n][0][c] << endl;
            ans = max(ans, f[n & 1][0][c]);
        }
        return  ans;
    }
};