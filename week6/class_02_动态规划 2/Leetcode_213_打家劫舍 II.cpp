/*
    ����DP���⣬��������
    1��͵��һ�䷿�ӣ����һ����벻͵
        f[1][1] = nums[1], f[1][0] = 0;
        Ŀ�� f[n][0];
    2����͵��һ�䷿�ӣ����һ���͵�ɲ�͵
        f[1][0] = 0, f[1][1] = -INF;
        Ŀ�� max(f[n][0],f[n][1]);
        ע�⣺dp���鲻��Ҫ���㣬��Ϊ�ڶ��μ����ֻ��ͷ��ʼת��
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