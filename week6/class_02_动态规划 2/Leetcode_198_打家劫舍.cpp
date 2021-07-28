/*
    f[i][j] 偷前i间房子，第i间 j = 1:0 偷：没偷的最高金额
        f[i][0] = max(f[i-1][0],f[i-1][1]);
        f[i][1] = f[i-1][0] + nums[i];
*/
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        nums.insert(nums.begin(), 0);
        vector<vector<int>> f(n + 1, vector<int>(2, -1000000000));
        f[0][0] = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= 1; j++) {
                if (j == 0) {
                    f[i][0] = max(f[i - 1][0], f[i - 1][1]);
                }
                else if (j == 1) {
                    f[i][1] = f[i - 1][0] + nums[i];
                }
            }
        }
        return max(f[n][0], f[n][1]);
    }
};