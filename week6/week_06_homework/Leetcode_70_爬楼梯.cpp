/*            集合：f[i] 所有爬到第i个台阶的方案数的集合
              属性：sum;
    动态规划
              状态计算：f[i] = f[i-1] + f[i-2];
*/
class Solution {
public:
    int climbStairs(int n) {
        vector<int> f(n + 1, 0);
        f[0] = 1;
        for (int i = 1; i <= n; i++) {
            f[i] += f[i - 1];
            if (i >= 2)
                f[i] += f[i - 2];
        }
        return f[n];
    }
};