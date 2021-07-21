//通常用于求解最优化问题：“最大值最小”，“最小值最大” 二分将求解转化为判定
//从花园中摘 m 束花需要等待的最少的天数 <= T;
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
        int res = 0;// 可以制作的花束
        int num = 0;//累计的花的数量
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