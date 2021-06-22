//解法一：利用哈希来做。
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> sum(n + 1, 0);
        for (int i = 1; i <= n; i++) {
            sum[i] = sum[i - 1] + nums[i - 1];
        }
        unordered_map<int, int> hash;
        hash[0] = 1;
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            ans += hash[sum[i] - k];
            hash[sum[i]]++;
        }
        return ans;
    }
};