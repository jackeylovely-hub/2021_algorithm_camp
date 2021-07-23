/*
    ���ִ𰸣�������С�ٶ�K������ת��Ϊ���ж��ܷ�����㽶��K֮ǰ���ܳ��꣬K֮����Գ���
             ����������
    �� H Сʱ�ڳԵ������㽶����С�ٶ� >= K
*/
class Solution {
public:
    int minEatingSpeed(vector<int>& _piles, int h) {
        //���ִ𰸵���,ע����ʼֵ���趨��һ��Ҫ����Ŀ�����ķ�Χ֮�� (l=0  error)
        piles = _piles;
        int l = 1, r = 1e9;
        while (l < r) {
            int mid = (l + r) >> 1;
            if (check(mid, h)) r = mid;
            else                     l = mid + 1;
        }
        return r;
    }

private:
    bool check(int k, int h) {
        int hour = 0;
        for (auto pile : piles)
            hour += (pile + k - 1) / k;
        return hour <= h;
    }
    vector<int> piles;
};