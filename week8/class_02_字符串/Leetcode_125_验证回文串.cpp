class Solution {
public:
    bool isPalindrome(string s) {
        string t;
        for (auto& ch : s) {
            if (ch >= '0' && ch <= '9' ||
                ch >= 'a' && ch <= 'z' ||
                ch >= 'A' && ch <= 'Z') {
                if (ch >= 'A' && ch <= 'Z') ch = ch - 'A' + 'a';
                t.push_back(ch);
            }
        }
        //cout << t << endl;
        int l = 0, r = t.size() - 1;
        while (l < r) {
            if (t[l] != t[r]) return false;
            l++, r--;
        }
        return true;
    }
};