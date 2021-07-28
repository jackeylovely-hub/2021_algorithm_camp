/*
    由于无法确定前一项的正负，所以我们需要存储最大最小f数组,进行状态转移的计算
    fmax[i]:以i结尾的乘积最大的子数组
*/
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        vector<int> fmax = vector<int>(n, 0);
        vector<int> fmin = vector<int>(n, 0);
        fmax[0] = nums[0];
        fmin[0] = nums[0];
        int ans = fmax[0];
        for (int i = 1; i < n; i++) {
            fmax[i] = max(nums[i], max(fmax[i - 1] * nums[i], fmin[i - 1] * nums[i]));
            fmin[i] = min(nums[i], min(fmin[i - 1] * nums[i], fmax[i - 1] * nums[i]));
            ans = max(fmax[i], ans);
        }
        return ans;
    }
};