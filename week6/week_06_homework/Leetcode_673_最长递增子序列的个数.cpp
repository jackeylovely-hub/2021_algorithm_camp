/*
    f[i] : 所有以nums[i]为结尾的递增子序列的长度;
    g[i] : 以nums[i]为结尾的最长上升子序列的个数;
    f[i] = max(f[i], f[j] + 1)  j<i, aj<ai;
    (1) f[i] < f[j]+1  g[i] = g[j];
    (2) f[i] == f[j]+1 g[i] += g[j];
*/
class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> f(n, 1), g(n, 1);
        int maxl = 0, cnt = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[j] < nums[i]) {
                    if (f[i] < f[j] + 1) f[i] = f[j] + 1, g[i] = g[j];
                    else if (f[i] == f[j] + 1) g[i] += g[j];
                }
            }
            if (maxl < f[i]) maxl = f[i], cnt = g[i];
            else if (maxl == f[i]) cnt += g[i];
        }
        return cnt;
    }
};