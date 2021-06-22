//自己AC的代码
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        int t = digits[n - 1] + 1;
        vector<int> res;
        //倒着遍历数组
        for (int i = n - 2; i >= 0; i--) {
            digits[i] *= 10;
            t += digits[i];
            res.push_back(t % 10);
            t /= 10;
        }
        //处理边界
        if (t > 9) {
            res.push_back(0);
            res.push_back(t / 10);
        }
        else if (t) {
            res.push_back(t);
        }
        //数组反转
        reverse(res.begin(), res.end());
        return res;
    }
};
//优化（最优解）：
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        int t = 1;
        vector<int> res;
        //倒着遍历数组
        for (int i = n - 1; i >= 0; i--) {
            t += digits[i];
            res.push_back(t % 10);
            t /= 10;
        }
        if (t) res.push_back(t);
        //数组反转
        reverse(res.begin(), res.end());
        return res;
    }
};
//解法二：
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        reverse(digits.begin(), digits.end());
        vector<int> res;
        int t = 1;//将加一看作个位的进位
        for (auto& digit : digits) {
            t += digit;
            res.push_back(t % 10);
            t /= 10;
        }
        if (t) res.push_back(t);
        reverse(res.begin(), res.end());
        return res;
    }
};