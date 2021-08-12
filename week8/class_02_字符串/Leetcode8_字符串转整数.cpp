class Solution {
public:
    int myAtoi(string s) {
        int index = 0;
        //会影响index的地方
        //1.丢弃前导空格
        while (index < s.size() && s[index] == ' ') index++;
        //2.检查正负号
        int sign = 1;
        if (s[index] == '-') sign = -1, index++;
        else if (s[index] == '+') index++;
        //3.数字转换为整数
        int res = 0;
        while (index < s.size() && s[index] >= '0' && s[index] <= '9') {
            if (res > (INT_MAX - (s[index] - '0')) / 10) {
                if (sign == -1) return INT_MIN;
                else return INT_MAX;
            }
            res = res * 10 + (s[index] - '0');
            index++;
        }
        return res * sign;
    }
};