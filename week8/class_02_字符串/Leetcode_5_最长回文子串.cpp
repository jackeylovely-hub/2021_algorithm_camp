//朴素枚举中点解法O(n^2)
class Solution {
public:
    string longestPalindrome(string s) {
        if (s.empty()) return " ";
        int n = s.size();
        s = " " + s;
        int anslen = 0;
        int ansstart = 0;
        //中心是一个字符
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
        //中心是两个字符
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
//二分优化
