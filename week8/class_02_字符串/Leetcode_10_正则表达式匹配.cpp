/*                    /集合：所有s[1~i]和p[1~j]的匹配方案；
         / 状态f[i][j]:
        /             \属性：bool 是否存在一个合法的方案；
动态规划              / p[j] != '*':
        \           /      f[i][j]=f[i-1][j-1]&&(s[i]==p[j]||p[j]=='.');
         \  状态计算
                    \
                     \ p[j] == '*':用多重背包的优化转移从O(n)->O(1);
                f[i][j]=f[i][j-2]||f[i-1][j]&&(s[i]==p[j-1]||p[j-1]=='.');
总体时间复杂度O(mn);
*/
class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.size(), n = p.size();
        //定义dp数组，全部初始化为false
        vector<vector<bool>> f(m + 1, vector<bool>(n + 1, false));
        //为了方便计算dp数组，字符串前面补上1位空格。
        s = " " + s, p = " " + p;
        //初始状态定义为true,即两个空格可以匹配
        f[0][0] = true;
        for (int i = 0; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                //if(j+1 <= n && p[j+1] =='*') continue;
                //防止状态越界的判断，最好放在if里面
                if (i && p[j] != '*') {
                    f[i][j] = f[i - 1][j - 1] && (s[i] == p[j] || p[j] == '.');
                }
                else if (p[j] == '*') {
                    //防止状态越界，状态转移方程二：
                    if (j >= 2)   f[i][j] = f[i][j] || f[i][j - 2];
                    if (i && (s[i] == p[j - 1] || p[j - 1] == '.'))
                        f[i][j] = f[i][j] || f[i - 1][j];
                }
            }
        }
        return f[m][n];
    }
};