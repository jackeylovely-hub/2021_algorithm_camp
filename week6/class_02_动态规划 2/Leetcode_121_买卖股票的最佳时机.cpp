/*
  ——————————i假设在第i天卖出，只需要找到前i-1天的最小值，相减就是结果，时间复杂度O(n);
*/
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int res = 0;
        for (int i = 0, premin = INT_MAX; i < prices.size(); i++) {
            res = max(res, prices[i] - premin);
            premin = min(premin, prices[i]);//更新最小值
        }
        return res;
    }
};