class Solution {
public:
    int mySqrt(int x) {
        //找最大的mid,使得mid*mid <= x(右边界);
        long long left = 0, right = x;
        while (left < right) {
            long long mid = left + right + 1 >> 1;
            if (mid * mid <= x) left = mid;
            else               right = mid - 1;
        }
        return right;
    }
};