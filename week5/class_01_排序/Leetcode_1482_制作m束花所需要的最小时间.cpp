//ͨ������������Ż����⣺�����ֵ��С��������Сֵ��� ���ֽ����ת��Ϊ�ж�
//�ӻ�԰��ժ m ������Ҫ�ȴ������ٵ����� <= T;
class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int left = 0, right = 1000000001;
        while (left < right) {
            int mid = (left + right) >> 1;
            if (check(bloomDay, m, k, mid)) right = mid;
            else left = mid + 1;
        }
        if (right == 1000000001) return -1;
        return right;
    }
private:
    bool check(vector<int>& bloomDay, int m, int k, int T) {
        int res = 0;// ���������Ļ���
        int num = 0;//�ۼƵĻ�������
        for (int i = 0; i < bloomDay.size(); i++) {
            if (bloomDay[i] <= T) {
                num++;
                if (num == k) {
                    num = 0;
                    res++;
                }
            }
            else {
                num = 0;
            }
        }
        return  res >= m;
    }
};