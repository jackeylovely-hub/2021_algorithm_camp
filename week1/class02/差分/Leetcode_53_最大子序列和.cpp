//未优化
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        vector<long long> sum(n + 1, 0);
        for (int i = 1; i <= n; i++) sum[i] = sum[i - 1] + nums[i - 1];

        vector<long long> pre(n + 1, 0);
        pre[0] = sum[0];
        for (int i = 1; i <= n; i++) pre[i] = min(pre[i - 1], sum[i]);

        long long ans = -1e10;
        for (int i = 1; i <= n; i++) {
            ans = max(ans, sum[i] - pre[i - 1]);
        }
        return ans;
    }
};
//优化后
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        vector<long long> sum(n + 1, 0);
        for (int i = 1; i <= n; i++) sum[i] = sum[i - 1] + nums[i - 1];

        vector<long long> pre(n + 1, 0);
        long long pre_min = sum[0];
        long long ans = -1e10;
        for (int i = 1; i <= n; i++) {
            ans = max(ans, sum[i] - pre_min);
            pre_min = min(pre_min, sum[i]);
        }
        return ans;
    }
};