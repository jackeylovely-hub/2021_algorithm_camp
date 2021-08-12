class Solution {
public:
    bool validPalindrome(string s) {
        return validPalindrome(s, 0, s.size() - 1, true);
    }
private:
    bool validPalindrome(const string& s, int l, int r, bool canDelete) {
        while (l < r) {
            if (s[l] == s[r]) l++, r--;
            else {
                if (canDelete) {
                    //ע��:ɾ�������l+,ɾ���ұ���r-, && �� || ������;
                    return validPalindrome(s, l, r - 1, false) || validPalindrome(s, l + 1, r, false);
                }
                else {
                    return false;
                }
            }
        }
        return true;
    }
};