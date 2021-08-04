/*  求yi + yj + |xi - xj| 的 最大值，其中 |xi - xj| <= k;
    设 j<i   xi - xj <= k, 当i增大时，j的取值范围的上下界(j的上界为i-1,j的下界
    为xi-k)同时增大。方法：滑动窗口的最大值。
    yi + yj + xi - xj =  yi + xi + yj - xj
*/
class Solution {
public:
    int findMaxValueOfEquation(vector<vector<int>>& points, int k) {
        int ans = -1000000000;
        deque<int> q;
        for (int i = 0; i < points.size(); i++) {
            //上界i-1,下界xi-k；
            //考虑两个选项j1 j2 j1比j2优的条件：y[j1]-x[j1] > y[j2]-x[j2]
            // 1.判断队头的合法性 xj: points[q.front()][0]; xj >= xi-k;
            while (!q.empty() && points[q.front()][0] < points[i][0] - k) {
                q.pop_front();
            }
            //2.取队头为最优解 yi + xi + yj - xj
            if (!q.empty()) ans = max(ans, points[i][0] + points[i][1] + points[q.front()][1] - points[q.front()][0]);
            //3.维护队列的单调性，确保新元素的插入
            while (!q.empty() && points[q.back()][1] - points[q.back()][0] <= points[i][1] - points[i][0]) q.pop_back();
            q.push_back(i);
        }
        return ans;
    }
};