/* 解法一：动态规划
    按照最后一个戳p划分子问题！
    f[l,r]表示戳破闭区间l~r的所有气球所能获得的最大硬币枚数(最后戳p)
    f[l][r] = max(f[l][r], f[l][p-1]+f[p+1][r]+nums[p]*nums[l-1]*nums[r+1])
    初值：l>r, f[l,r] = 0;
    目标：f[1,n]
*/
class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        //f[0....n][0...n]
        vector<vector<int>> f(n + 2, vector<int>(n + 2, 0));
        //先枚举区间长度
        for (int len = 1; len <= n; len++) {
            //枚举区间左端点
            for (int l = 1; l <= n - len + 1; l++) {
                int r = l + len - 1;
                //枚举决策
                for (int p = l; p <= r; p++) {
                    f[l][r] = max(f[l][r], f[l][p - 1] + f[p + 1][r] + nums[p] * nums[l - 1] * nums[r + 1]);
                }
            }
        }
        return f[1][n];
    }
};
//解法二：记忆化搜索
class Solution {
public:
    int maxCoins(vector<int>& _nums) {
        nums = _nums;
        int n = nums.size();
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        f = vector<vector<int>>(n + 1, vector<int>(n + 1, -1));
        return dfs(1, n);
    }
private:
    int dfs(int l, int r) {
        //递归终止条件 l = r 可以不终止
        if (l > r) return 0;
        if (f[l][r] != -1) return f[l][r];
        //赋初值
        f[l][r] = 0;
        for (int p = l; p <= r; p++) {
            f[l][r] = max(f[l][r], dfs(l, p - 1) + dfs(p + 1, r) + nums[p] * nums[l - 1] * nums[r + 1]);
        }
        return f[l][r];
    }

    vector<vector<int>> f;
    vector<int> nums;
};