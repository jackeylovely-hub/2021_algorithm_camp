//两数之和改版
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        for (int i = 0; i < nums.size(); i++) {
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            auto twosums = twoSum(nums, i + 1, -nums[i]);
            for (auto twosum : twosums) {
                res.push_back({ nums[i],twosum[0],twosum[1] });
            }
        }
        return res;
    }
private:
    vector<vector<int>> twoSum(vector<int>& numbers, int start, int target) {
        int j = numbers.size() - 1;
        vector<vector<int>> ans;
        for (int i = start; i < numbers.size(); i++) {
            if (i > start && numbers[i] == numbers[i - 1]) continue;
            while (i < j && numbers[i] + numbers[j] > target) j--;

            if (i < j && numbers[i] + numbers[j] == target) {
                ans.push_back({ numbers[i],numbers[j] });
            }
        }
        return ans;
    }
};