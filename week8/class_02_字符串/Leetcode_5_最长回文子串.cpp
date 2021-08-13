//����ö���е�ⷨO(n^2)
class Solution {
public:
    string longestPalindrome(string s) {
        if (s.empty()) return " ";
        int n = s.size();
        s = " " + s;
        int anslen = 0;
        int ansstart = 0;
        //������һ���ַ�
        for (int center = 1; center <= n; center++) {
            int l = center - 1, r = center + 1;
            while (l > 0 && r <= n && s[l] == s[r]) {
                l--, r++;
            }
            //s[l+1,r-1]
            if (r - l - 1 > anslen) {
                anslen = r - l - 1;
                ansstart = l + 1;
            }
        }
        //�����������ַ�
        for (int center = 1; center < n; center++) {
            int l = center, r = center + 1;
            while (l > 0 && r <= n && s[l] == s[r]) {
                l--, r++;
            }
            //s[l+1,r-1]
            if (r - l - 1 > anslen) {
                anslen = r - l - 1;
                ansstart = l + 1;
            }
        }
        return s.substr(ansstart, anslen);
    }
};
//����+�ַ�����ϣ�Ż�����ȻԽ�磩
typedef unsigned long long ULL;
class Solution {
public:
    string longestPalindrome(string s) {
        if (s.empty()) return " ";
        n = s.size();
        s = " " + s;
        //��ʼ��
        prehash = vector<ULL>(n + 1, 0);
        prehash[0] = 0;
        sufhash = vector<ULL>(n + 2, 0);
        sufhash[n + 1] = 0;
        p131 = vector<ULL>(n + 1, 0);
        p131[0] = 1;
        //Ԥ����ǰ׺��ϣ
        for (int i = 1; i <= n; i++) {
            prehash[i] = prehash[i - 1] * 131 + (s[i] - 'a' + 1);
            p131[i] = p131[i - 1] * 131;
        }
        //Ԥ�����׺��ϣ
        for (int i = n; i; i--) {
            sufhash[i] = sufhash[i + 1] * 131 + (s[i] - 'a' + 1);
        }
        int anslen = 0;
        int ansstart = 0;
        //������һ���ַ�
        for (int center = 1; center <= n; center++) {
            //lenL�����������չ�ĳ���
            int lenL = 0, lenR = n;
            while (lenL < lenR) {
                int len = (lenL + lenR + 1) / 2;
                //ע�����ұ߽�ļӼ�len
                int l = center - len;
                int r = center + len;
                if (isPalindrome(l, r)) lenL = len;
                else                  lenR = len - 1;
            }
            if (2 * lenL + 1 > anslen) {
                anslen = 2 * lenL + 1;
                ansstart = center - lenL;
            }
        }
        //�����������ַ�
        for (int center = 1; center < n; center++) {
            int lenL = 0, lenR = n;
            while (lenL < lenR) {
                int len = (lenL + lenR + 1) / 2;
                int l = center - len + 1;
                int r = center + len;
                if (isPalindrome(l, r)) lenL = len;
                else                    lenR = len - 1;
            }
            if (2 * lenL > anslen) {
                anslen = 2 * lenL;
                ansstart = center - lenL + 1;
            }
        }
        return s.substr(ansstart, anslen);
    }
private:
    //�ַ�����ϣ�ж��Ƿ�Ϊ����
    bool isPalindrome(int l, int r) {
        //ע��Խ�����
        if (l < 1 || r > n) return false;
        //�ݹ���ֹ����
        if (l > r) return true;
        //ǰ׺��ϣֵ���ں�׺��ϣֵ
        return getPre(l, r) == getSuf(l, r);
    }
    ULL getPre(int l, int r) {
        return prehash[r] - prehash[l - 1] * p131[r - l + 1];
    }
    ULL getSuf(int l, int r) {
        return sufhash[l] - sufhash[r + 1] * p131[r - l + 1];
    }
    vector<ULL> prehash, sufhash, p131;
    int n;
};
//����+�ַ�����ϣ�Ż���ȡģ��
typedef long long LL;
class Solution {
public:
    string longestPalindrome(string s) {
        if (s.empty()) return " ";
        n = s.size();
        s = " " + s;
        //��ʼ��
        prehash = vector<LL>(n + 1, 0);
        prehash[0] = 0;
        sufhash = vector<LL>(n + 2, 0);
        sufhash[n + 1] = 0;
        p131 = vector<LL>(n + 1, 0);
        p131[0] = 1;
        //Ԥ����ǰ׺��ϣ
        for (int i = 1; i <= n; i++) {
            prehash[i] = (prehash[i - 1] * 131 + (s[i] - 'a' + 1)) % P;
            p131[i] = (p131[i - 1] * 131) % P;
        }
        //Ԥ�����׺��ϣ
        for (int i = n; i; i--) {
            sufhash[i] = (sufhash[i + 1] * 131 + (s[i] - 'a' + 1)) % P;
        }
        int anslen = 0;
        int ansstart = 0;
        //������һ���ַ�
        for (int center = 1; center <= n; center++) {
            //lenL�����������չ�ĳ���
            int lenL = 0, lenR = n;
            while (lenL < lenR) {
                int len = (lenL + lenR + 1) / 2;
                //ע�����ұ߽�ļӼ�len
                int l = center - len;
                int r = center + len;
                if (isPalindrome(l, r)) lenL = len;
                else                  lenR = len - 1;
            }
            if (2 * lenL + 1 > anslen) {
                anslen = 2 * lenL + 1;
                ansstart = center - lenL;
            }
        }
        //�����������ַ�
        for (int center = 1; center < n; center++) {
            int lenL = 0, lenR = n;
            while (lenL < lenR) {
                int len = (lenL + lenR + 1) / 2;
                int l = center - len + 1;
                int r = center + len;
                if (isPalindrome(l, r)) lenL = len;
                else                  lenR = len - 1;
            }
            if (2 * lenL > anslen) {
                anslen = 2 * lenL;
                ansstart = center - lenL + 1;
            }
        }
        return s.substr(ansstart, anslen);
    }
private:
    //�ַ�����ϣ�ж��Ƿ�Ϊ����
    bool isPalindrome(int l, int r) {
        //ע��Խ�����
        if (l < 1 || r > n) return false;
        //�ݹ���ֹ����
        if (l > r) return true;
        //ǰ׺��ϣֵ���ں�׺��ϣֵ
        return getPre(l, r) == getSuf(l, r);
    }
    LL getPre(int l, int r) {
        return ((prehash[r] - prehash[l - 1] * p131[r - l + 1]) % P + P) % P;
    }
    LL getSuf(int l, int r) {
        return ((sufhash[l] - sufhash[r + 1] * p131[r - l + 1]) % P + P) % P;
    }
    vector<LL> prehash, sufhash, p131;
    int n;
    const int P = 1e9 + 7;
};