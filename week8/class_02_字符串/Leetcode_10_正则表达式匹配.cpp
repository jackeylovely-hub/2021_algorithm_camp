/*                    /���ϣ�����s[1~i]��p[1~j]��ƥ�䷽����
         / ״̬f[i][j]:
        /             \���ԣ�bool �Ƿ����һ���Ϸ��ķ�����
��̬�滮              / p[j] != '*':
        \           /      f[i][j]=f[i-1][j-1]&&(s[i]==p[j]||p[j]=='.');
         \  ״̬����
                    \
                     \ p[j] == '*':�ö��ر������Ż�ת�ƴ�O(n)->O(1);
                f[i][j]=f[i][j-2]||f[i-1][j]&&(s[i]==p[j-1]||p[j-1]=='.');
����ʱ�临�Ӷ�O(mn);
*/
class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.size(), n = p.size();
        //����dp���飬ȫ����ʼ��Ϊfalse
        vector<vector<bool>> f(m + 1, vector<bool>(n + 1, false));
        //Ϊ�˷������dp���飬�ַ���ǰ�油��1λ�ո�
        s = " " + s, p = " " + p;
        //��ʼ״̬����Ϊtrue,�������ո����ƥ��
        f[0][0] = true;
        for (int i = 0; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                //if(j+1 <= n && p[j+1] =='*') continue;
                //��ֹ״̬Խ����жϣ���÷���if����
                if (i && p[j] != '*') {
                    f[i][j] = f[i - 1][j - 1] && (s[i] == p[j] || p[j] == '.');
                }
                else if (p[j] == '*') {
                    //��ֹ״̬Խ�磬״̬ת�Ʒ��̶���
                    if (j >= 2)   f[i][j] = f[i][j] || f[i][j - 2];
                    if (i && (s[i] == p[j - 1] || p[j - 1] == '.'))
                        f[i][j] = f[i][j] || f[i - 1][j];
                }
            }
        }
        return f[m][n];
    }
};