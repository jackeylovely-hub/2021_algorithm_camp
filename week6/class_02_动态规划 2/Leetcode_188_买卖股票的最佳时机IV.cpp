/*
     dp[i][j][k]:��i�����ʱ���ֲ�Ϊj,���״���Ϊk���������
*/
class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        prices.insert(prices.begin(), 0);
        //ע��f�����ʼ��
        vector<vector<vector<int>>> f(n + 1, vector<vector<int>>(2, vector<int>(k + 1, -1000000000)));
        f[0][0][0] = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= 1; j++) {
                for (int c = 0; c <= k; c++) {
                    //ʲôҲ����
                    f[i][j][c] = f[i - 1][j][c];
                    if (j == 0) {
                        //������Ʊ
                        f[i][0][c] = max(f[i][0][c], f[i - 1][1][c] + prices[i]);
                    }
                    else if (j == 1 && c > 0) {
                        //�����Ʊ
                        f[i][1][c] = max(f[i][1][c], f[i - 1][0][c - 1] - prices[i]);
                    }
                }
            }
        }
        //�������һ�����ʱ�����н��״�������õ���������ֵ
        int ans = 0;
        for (int c = 0; c <= k; c++) {
            ans = max(ans, f[n][0][c]);
        }
        return ans;
    }
};