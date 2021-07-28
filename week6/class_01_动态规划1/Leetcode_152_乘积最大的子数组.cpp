/*
    �����޷�ȷ��ǰһ�������������������Ҫ�洢�����Сf����,����״̬ת�Ƶļ���
    fmax[i]:��i��β�ĳ˻�����������
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