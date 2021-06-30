class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        used = vector<bool>(nums.size(), false);
        dfs(nums, 0);
        return ans;
    }

    void dfs(vector<int>& nums, int index) {
        if (index == nums.size()) {
            ans.push_back(res);
            return;
        }
        for (int i = 0; i < nums.size(); i++) {
            if (!used[i]) {
                res.push_back(nums[i]);
                used[i] = true;
                dfs(nums, index + 1);
                used[i] = false;
                res.pop_back();
            }
        }
    }

private:
    vector<int>  res;
    vector<bool> used;
    vector<vector<int>> ans;
};