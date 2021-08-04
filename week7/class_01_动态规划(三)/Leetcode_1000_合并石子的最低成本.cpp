/*
    f[l][r][i]:表示把l~r合并成i堆的最低成本
    考虑第一段
    f[l][r][i] = min(f[l][p][1], f[p+1][r][i-1]), i>1;
*/
class Solution {
public:
    int mergeStones(vector<int>& stones, int k) {
        int n = stones.size();
        stones.insert(stones.begin(), 0);
        vector<int> sum(n + 1, 0);
        //求前缀和时候小心求错 sum[i] = sum[i - 1] + stones[i-1]这是不补零的情况
        for (int i = 1; i <= n; i++) sum[i] = sum[i - 1] + stones[i];

        vector<vector<vector<int>>> f(n + 2, vector<vector<int>>(n + 2, vector<int>(k + 1, 1000000000)));
        for (int i = 1; i <= n; i++) f[i][i][1] = 0;
        //从两堆石子开始遍历
        for (int len = 2; len <= n; len++)
            for (int l = 1; l <= n - len + 1; l++) {
                int r = l + len - 1;
                for (int i = 2; i <= k; i++)
                    //将l~r分成i堆的最小花费  l~p分1堆 p+1~r分i-1堆 计算出f[l][r][k]
                    for (int p = l; p <= r; p++)
                        f[l][r][i] = min(f[l][r][i], f[l][p][1] + f[p + 1][r][i - 1]);
                //最后将l~r中的k堆合成一堆;
                f[l][r][1] = min(f[l][r][1], f[l][r][k] + sum[r] - sum[l - 1]);
            }

        if (f[1][n][1] >= 1000000000) return -1;
        return f[1][n][1];
    }
};