/*
    设 f(i)表示通过平方数组成i所需要完全平方数的最少数量。
    初始时，f(0)=0,其余待定。
    转移时，对于一个i枚举j，f(i)=min(f(i−j∗j)+1)，其中 1≤j≤根号i。
    最终答案为 f(n)。
*/
class Solution {
public:
    int numSquares(int n) {
        vector<int> f(n + 1, n);
        f[0] = 0;
        for (int i = 1; i <= n; i++)
            for (int j = 1; j * j <= i; j++)
                f[i] = min(f[i], f[i - j * j] + 1);
        return f[n];
    }
};