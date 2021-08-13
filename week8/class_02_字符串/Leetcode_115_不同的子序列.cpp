/*         /- ״̬��ʾ: ���ϣ�f[i,j]:����s[1~i]��t[1~j]ƥ��������еļ���
          /            ���ԣ�����
    dp����
          \
           \- ״̬����: ���һ����s[i]ѡ����߲�ѡ
                            ��ѡ��f[i-1][j]
                            ѡ��f[i-1][j-1]
*/
class Solution {
public:
    int numDistinct(string s, string t) {
        int m = s.size(), n = t.size();
        vector<vector<long long>> f(m + 1, vector<long long>(n + 1, 0));
        s = " " + s;
        t = " " + t;
        //��ʼ��:
        for (int i = 0; i <= m; i++) f[i][0] = 1;
        for (int i = 1; i <= m; i++)
            for (int j = 1; j <= n; j++) {
                f[i][j] = f[i - 1][j];
                //��ֹ�м���Խ��
                if (s[i] == t[j] && f[i][j] <= 2147483647 - f[i - 1][j - 1]) {
                    f[i][j] += f[i - 1][j - 1];
                }
            }
        return f[m][n];
    }
};