/*
* 当n为偶数时：pow(x,n)=pow(x,n/2) * pow(x,n/2);
* 当n为奇数时：pow(x,n)=pow(x,n/2) * pow(x,n/2) * x;
* 为了降低时间复杂度 用变量temp存储pow(x,n/2)；
*/
class Solution {
public:
    double myPow(double x, long long n) {
        if (n < 0)  return 1 / myPow(x, -n);
        if (n == 0) return 1;
        double temp = myPow(x, n / 2);
        if (n % 2 == 0) {
            return temp * temp;
        }
        else {
            return temp * temp * x;
        }
    }
};






