/*
    �� D ���ڽ����ʹ��ϵ����а����ʹ�Ĵ�������������� >= T
    T֮ǰ����false,T֮����true,����������
*/
class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int l = 0, r = 0;
        for (int i = 0; i < weights.size(); i++) {
            l = max(l, weights[i]);
            r += weights[i];
        }
        while (l < r) {
            int mid = (l + r) >> 1;
            if (check(weights, days, mid)) r = mid;
            else           l = mid + 1;
        }
        return r;
    }
private:
    bool check(vector<int>& weights, int days, int T) {
        //̰�ĵļ�
        int cur = 0;
        int time = 1;
        for (int i = 0; i < weights.size(); i++) {
            if (cur + weights[i] > T) {
                time++;
                cur = 0;
            }
            cur += weights[i];
        }
        return time <= days;
    }
};