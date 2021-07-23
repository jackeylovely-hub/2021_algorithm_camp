/*
    二分答案：将求最小速度K的问题转化为，判断能否吃完香蕉，K之前不能吃完，K之后可以吃完
             具有两段性
    在 H 小时内吃掉所有香蕉的最小速度 >= K
*/
class Solution {
public:
    int minEatingSpeed(vector<int>& _piles, int h) {
        //二分答案的题,注意起始值的设定，一定要在题目给定的范围之内 (l=0  error)
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