//�Լ�AC�Ĵ���
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        int t = digits[n - 1] + 1;
        vector<int> res;
        //���ű�������
        for (int i = n - 2; i >= 0; i--) {
            digits[i] *= 10;
            t += digits[i];
            res.push_back(t % 10);
            t /= 10;
        }
        //����߽�
        if (t > 9) {
            res.push_back(0);
            res.push_back(t / 10);
        }
        else if (t) {
            res.push_back(t);
        }
        //���鷴ת
        reverse(res.begin(), res.end());
        return res;
    }
};
//�Ż������Ž⣩��
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        int t = 1;
        vector<int> res;
        //���ű�������
        for (int i = n - 1; i >= 0; i--) {
            t += digits[i];
            res.push_back(t % 10);
            t /= 10;
        }
        if (t) res.push_back(t);
        //���鷴ת
        reverse(res.begin(), res.end());
        return res;
    }
};
//�ⷨ����
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        reverse(digits.begin(), digits.end());
        vector<int> res;
        int t = 1;//����һ������λ�Ľ�λ
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