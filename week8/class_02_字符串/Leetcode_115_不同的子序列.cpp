/*         /- 状态表示: 集合：f[i,j]:所有s[1~i]与t[1~j]匹配的子序列的集合
          /            属性：数量
    dp分析
          \
           \- 状态计算: 最后一步：s[i]选择或者不选
                            不选：f[i-1][j]
                            选择：f[i-1][j-1]
*/
class Solution {
public:
    int numDistinct(string s, string t) {
        int m = s.size(), n = t.size();
        vector<vector<long long>> f(m + 1, vector<long long>(n + 1, 0));
        s = " " + s;
        t = " " + t;
        //初始化:
        for (int i = 0; i <= m; i++) f[i][0] = 1;
        for (int i = 1; i <= m; i++)
            for (int j = 1; j <= n; j++) {
                f[i][j] = f[i - 1][j];
                //防止中间结果越界
                if (s[i] == t[j] && f[i][j] <= 2147483647 - f[i - 1][j - 1]) {
                    f[i][j] += f[i - 1][j - 1];
                }
            }
        return f[m][n];
    }
};