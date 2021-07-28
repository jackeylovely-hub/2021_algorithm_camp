/*
    完全背包问题：背包的容量amount,物品体积，价值=1;
*/
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<int> f(amount + 1, 0);
        f[0] = 1;//背包为空时算一种方案
        for (int i = 0; i < n; i++)
            for (int j = coins[i]; j <= amount; j++)
                f[j] += f[j - coins[i]];
        return f[amount];
    }
};