/*
  ��������������������i�����ڵ�i��������ֻ��Ҫ�ҵ�ǰi-1�����Сֵ��������ǽ����ʱ�临�Ӷ�O(n);
*/
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int res = 0;
        for (int i = 0, premin = INT_MAX; i < prices.size(); i++) {
            res = max(res, prices[i] - premin);
            premin = min(premin, prices[i]);//������Сֵ
        }
        return res;
    }
};