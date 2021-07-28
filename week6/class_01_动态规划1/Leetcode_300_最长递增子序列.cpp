/*
    决策与状态的平衡
    dp:前i个数，以a[i]为结尾的最长上升子序列。
    dp[i] = max(dp[i],dp[j]+1) a[j]<a[i],j<i;
*/
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        //注意初始化;
        vector<int> dp = vector<int>(n, 1);
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[j] < nums[i]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
        }
        int ans = 0;
        for (int i = 0; i < n; i++) {
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};