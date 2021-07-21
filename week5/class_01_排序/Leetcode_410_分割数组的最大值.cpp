//二分答案：将求解最优化问题转化为判断解是否合理
//最小化“m个子数组的和的最大值”
//判定是否存在“m个子数组的和的最大值”<=T;
//能否将nums分成m个连续的子数组，使各自和的最大值=T  只有18 23 24 25 合法
//能否将nums分成m个连续的子数组，使各自和的最大值<=T  17之前不合法，18之后合法，符合两段性
class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        int left = 0;
        int right = 0;
        for (int i = 0; i < nums.size(); i++) {
            left = max(left, nums[i]);
            right += nums[i];
        }
        while (left < right) {
            int mid = (left + right) >> 1;
            //查找第一个使得check == true的点；
            if (check(nums, m, mid)) right = mid;
            else           left = mid + 1;
        }
        return right;
    }
private:
    bool check(vector<int>& nums, int m, int T) {
        int subSum = 0;
        int subGroup = 1;
        for (int i = 0; i < nums.size(); i++) {
            if (subSum + nums[i] <= T) {
                subSum += nums[i];
            }
            else {
                subSum = nums[i];
                subGroup++;
            }
        }
        return subGroup <= m;
    }
};