/*
    每天获得收益的累加，如果是负的加0;
*/
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int res = 0;
        for (int i = 0; i + 1 < prices.size(); i++) {
            res += max(0, prices[i + 1] - prices[i]);
        }
        return res;
    }
};