/*字符串哈希面试模板*/
typedef unsigned long long ULL;
class Solution {
public:
    int strStr(string s, string t) {
        if (t.empty()) return 0;
        int n = s.size(), m = t.size();
        s = " " + s;
        t = " " + t;
        int P = 131, mod = 1e9 + 7;
        //预处理 p^n 和 s的哈希数组
        h.push_back(0);
        for (int i = 1; i <= n; i++) {
            h.push_back(h[i - 1] * P + s[i]);
        }
        //预处理t的哈希值
        ULL thash = 0;
        p.push_back(1);
        for (int i = 1; i <= m; i++) {
            thash = thash * P + t[i];
            p.push_back(p[i - 1] * P);
        }
        //滑动窗的形式
        for (int i = m; i <= n; i++) {
            //s[i-m+1 , i] 与t[m];
            if (get(i - m + 1, i) == thash &&
                s.substr(i - m + 1, m) == t.substr(1, m)) {
                return i - m;
            }
        }
        return -1;
    }
private:
    ULL get(int l, int r) {
        return h[r] - h[l - 1] * p[r - l + 1];
    }
    vector<ULL> h;
    vector<ULL> p;
};