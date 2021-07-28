/* �ⷨ�����ص�DP+�ռ��Ż�
    f[i][j]:��i��������ֲ���Ϊj,������������;
        f[i-1][j]--->f[i][j] = max(f[i][j], f[i-1][j])             #ʲôҲ����
        f[i-1][j]--->f[i][0] = max(f[i][0], f[i-1][1] + prices[i]) #��
        f[i-1][j]--->f[i][1] = max(f[i][1], f[i-1][0] - prices[i]) #��
*/
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        prices.insert(prices.begin(), 0);
        vector<vector<int>> f(2, vector<int>(2, -1000000000));
        f[0][0] = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= 1; j++) {
                f[i & 1][j] = max(f[i & 1][j], f[(i - 1) & 1][j]);
                if (j == 0) {
                    f[i & 1][0] = max(f[i & 1][0], f[(i - 1) & 1][1] + prices[i]);
                }
                else if (j == 1) {
                    f[i & 1][1] = max(f[i & 1][1], f[(i - 1) & 1][0] - prices[i]);
                }
            }
        }
        return f[n & 1][0];
    }
};