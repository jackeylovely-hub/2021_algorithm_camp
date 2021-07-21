/*
    在 D 天内将传送带上的所有包裹送达的船的最低运载能力 >= T
    T之前都是false,T之后是true,具有两段性
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
        //贪心的加
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