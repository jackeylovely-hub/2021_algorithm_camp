/*
    环形DP问题，拆开来看：
    1：偷第一间房子，最后一间必须不偷
        f[1][1] = nums[1], f[1][0] = 0;
        目标 f[n][0];
    2：不偷第一间房子，最后一间可偷可不偷
        f[1][0] = 0, f[1][1] = -INF;
        目标 max(f[n][0],f[n][1]);
        注意：dp数组不需要清零，因为第二次计算又会从头开始转移
*/
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];
        nums.insert(nums.begin(), 0);
        int ans = -1e9;
        vector<vector<int>> f(n + 1, vector<int>(2, -1e9));
        f[1][0] = 0, f[1][1] = nums[1];
        for (int i = 2; i <= n; i++) {
            for (int j = 0; j <= 1; j++) {
                f[i][0] = max(f[i - 1][1], f[i - 1][0]);
                f[i][1] = f[i - 1][0] + nums[i];
            }
        }
        ans = f[n][0];
        f[1][0] = 0, f[1][1] = -1e9;
        for (int i = 2; i <= n; i++) {
            for (int j = 0; j <= 1; j++) {
                f[i][0] = max(f[i - 1][1], f[i - 1][0]);
                f[i][1] = f[i - 1][0] + nums[i];
            }
        }
        ans = max(ans, max(f[n][0], f[n][1]));
        return ans;
    }
};