class Solution {
public:
    int mySqrt(int x) {
        //������mid,ʹ��mid*mid <= x(�ұ߽�);
        long long left = 0, right = x;
        while (left < right) {
            long long mid = left + right + 1 >> 1;
            if (mid * mid <= x) left = mid;
            else               right = mid - 1;
        }
        return right;
    }
};