/*
    ��������ת����0-1�������⣬����������Ϊsum/2,ÿ����ֻ��һ�Σ���Ʒ�����Ϊÿ�����Ĵ�С
*/
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int  n = nums.size();
        nums.insert(nums.begin(), 0);
        int sum = 0;
        for (int i = 0; i <= n; i++) sum += nums[i];
        //��Ϊ������sum/2�޷�������ƴ��
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