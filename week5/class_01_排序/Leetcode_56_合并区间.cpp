//解法一：排序解法
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        //双关键字排序
        sort(intervals.begin(), intervals.end(),
            [](vector<int> a, vector<int> b) {
            return a[0] < b[0] || (a[0] == b[0] && a[1] < b[1]);
        });
        int left = -1;
        int far = -1;
        for (auto& interval : intervals) {
            int start = interval[0];
            int end = interval[1];
            //如果起点小于，最远点，可以合并，更新最远点
            if (start <= far) {
                far = max(far, end);
            }
            else {
                //存储原来的结果
                if (far >= 0) ans.push_back({ left,far });
                //新开一段
                left = start;
                far = end;
            }
        }
        //把最后一段加进来
        if (far >= 0) ans.push_back({ left,far });
        return ans;
    }
};
//方法二：运用差分来做，注意区间最后坐标位置+1；
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        vector<pair<int, int>> events;//pair:位置，(+1/-1);
        for (auto& interval : intervals) {
            events.push_back(make_pair(interval[0], 1));
            events.push_back(make_pair(interval[1] + 1, -1));
        }
        sort(events.begin(), events.end());
        int left = 0;
        int count = 0;
        for (auto& event : events) {
            //如果加之前是0
            if (count == 0) {
                left = event.first;
            }
            count += event.second;
            //加之后为0,需要产生一个序列了
            if (count == 0) {
                ans.push_back({ left, event.first - 1 });
            }
        }
        return ans;
    }
};
