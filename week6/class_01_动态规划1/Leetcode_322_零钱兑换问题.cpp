/*
    dp(n):状态兑换n元需要的最少硬币枚数为dp(n);
*/
const int  INF = 1e9;
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, 0);
        for (int i = 1; i <= amount; i++) {
            dp[i] = INF;
            for (int j = 0; j < coins.size(); j++) {
                if (i - coins[j] >= 0)
                    dp[i] = min(dp[i], dp[i - coins[j]] + 1);
            }
        }
        if (dp[amount] == INF) return -1;
        return dp[amount];
    }
};