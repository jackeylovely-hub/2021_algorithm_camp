//解法一：递归未剪枝
class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        this->n = n;
        this->k = k;
        dfs(1);
        return ans;
    }
    void dfs(int index) {
        if (index == n + 1) {
            if (res.size() == k) {
                ans.push_back(res);
            }
            return;
        }
        dfs(index + 1);
        res.push_back(index);
        dfs(index + 1);
        res.pop_back();
    }

private:
    vector<int> res;
    vector<vector<int>> ans;
    int n;
    int k;
};
//解法二：递归剪枝
class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        this->n = n;
        this->k = k;
        dfs(1);
        return ans;
    }
    void dfs(int index) {
        //选的数已经超过k个，或者把剩下的数全选上也不够k个
        if (res.size() > k || res.size() + n - index + 1 < k) {
            return;
        }
        if (index == n + 1) {
            if (res.size() == k) {
                ans.push_back(res);
            }
            return;
        }
        dfs(index + 1);
        res.push_back(index);
        dfs(index + 1);
        res.pop_back();
    }
private:
    vector<int> res;
    vector<vector<int>> ans;
    int n;
    int k;
};







