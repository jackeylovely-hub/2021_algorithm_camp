/*
    由于从上往下枚举需要考虑边界问题，采用从下往上枚举的方式;
                    集合：f[i][j] 从底向上走到(i,j)的路径和
            状态表示
                    属性：min
    动态规划
            状态计算：f[i][j] = min(f[i+1][j] , f[i+1][j+1]) + nums[i][j];
*/
class Solution {
public:
    int minimumTotal(vector<vector<int>>& f) {
        for (int i = f.size() - 2; i >= 0; i--) {
            for (int j = 0; j <= i; j++) {
                f[i][j] += min(f[i + 1][j], f[i + 1][j + 1]);
            }
        }
        return f[0][0];
    }
};