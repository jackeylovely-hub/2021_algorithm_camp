class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        dfs(nums, 0);
        return ans;
    }
    void dfs(vector<int>& nums, int index) {
        if (index == nums.size()) {
            ans.push_back(res);
            return;
        }
        //��ѡ
        dfs(nums, index + 1);
        //ѡ
        res.push_back(nums[index]);
        dfs(nums, index + 1);
        res.pop_back();
    }
private:
    vector<int> res;
    vector<vector<int>> ans;
};