//���ֲ���
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int l = 0, r = nums.size() - 1;
        while (l < r) {
            //ÿ�������������֮һ
            int lmid = l + r >> 1;
            int rmid = lmid + 1;
            if (nums[lmid] < nums[rmid]) l = lmid + 1;
            else r = rmid - 1;
        }
        return l;
    }
};