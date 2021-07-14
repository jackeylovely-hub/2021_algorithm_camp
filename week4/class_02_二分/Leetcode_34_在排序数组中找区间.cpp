class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans;
        //��ʼλ�ã���һ�� >=target���� [0~n-1]+[n��ʾ������]
        int left = 0, right = nums.size();
        while (left < right) {
            int mid = left + right >> 1;
            if (nums[mid] >= target) right = mid;
            else                    left = mid + 1;
        }
        ans.push_back(right);
        //����λ�ã����һ��>=target����[-1��ʾ������]+[0~n-1]
        left = -1, right = nums.size() - 1;
        while (left < right) {
            int mid = left + right + 1 >> 1;
            if (nums[mid] <= target) left = mid;
            else                    right = mid - 1;
        }
        ans.push_back(right);

        if (ans[0] > ans[1])  ans = { -1,-1 };
        return ans;
    }
};