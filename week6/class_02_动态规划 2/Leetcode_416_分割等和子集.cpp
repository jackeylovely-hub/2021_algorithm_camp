/*
    根据题意转化成0-1背包问题，背包的容量为sum/2,每个数只用一次，物品的体积为每个数的大小
*/
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int  n = nums.size();
        nums.insert(nums.begin(), 0);
        int sum = 0;
        for (int i = 0; i <= n; i++) sum += nums[i];
        //和为奇数，sum/2无法用整数拼成
        if (sum % 2) return false;
        sum /= 2;
        vector<bool> f(sum + 1, false);
        f[0] = true;
        for (int i = 1; i <= n; i++) {
            for (int j = sum; j >= nums[i]; j--) {
                f[j] = f[j] | f[j - nums[i]];
            }
        }
        return f[sum];
    }
};