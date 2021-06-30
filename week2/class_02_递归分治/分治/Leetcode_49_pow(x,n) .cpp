/*
* ��nΪż��ʱ��pow(x,n)=pow(x,n/2) * pow(x,n/2);
* ��nΪ����ʱ��pow(x,n)=pow(x,n/2) * pow(x,n/2) * x;
* Ϊ�˽���ʱ�临�Ӷ� �ñ���temp�洢pow(x,n/2)��
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






