
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> s;//值到下标的映射
        //j<i,在i之前查找，防止查到i本身。
        for (int i = 0; i < nums.size(); i++) {
            if (s.find(target - nums[i]) != s.end()) {
                return { s[target - nums[i]], i };
            }
            s[nums[i]] = i;//动态插入
        }
        return {};
    }
};