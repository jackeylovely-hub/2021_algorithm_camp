//�ⷨһ������ⷨ
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        //˫�ؼ�������
        sort(intervals.begin(), intervals.end(),
            [](vector<int> a, vector<int> b) {
            return a[0] < b[0] || (a[0] == b[0] && a[1] < b[1]);
        });
        int left = -1;
        int far = -1;
        for (auto& interval : intervals) {
            int start = interval[0];
            int end = interval[1];
            //������С�ڣ���Զ�㣬���Ժϲ���������Զ��
            if (start <= far) {
                far = max(far, end);
            }
            else {
                //�洢ԭ���Ľ��
                if (far >= 0) ans.push_back({ left,far });
                //�¿�һ��
                left = start;
                far = end;
            }
        }
        //�����һ�μӽ���
        if (far >= 0) ans.push_back({ left,far });
        return ans;
    }
};
//�����������ò��������ע�������������λ��+1��
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        vector<pair<int, int>> events;//pair:λ�ã�(+1/-1);
        for (auto& interval : intervals) {
            events.push_back(make_pair(interval[0], 1));
            events.push_back(make_pair(interval[1] + 1, -1));
        }
        sort(events.begin(), events.end());
        int left = 0;
        int count = 0;
        for (auto& event : events) {
            //�����֮ǰ��0
            if (count == 0) {
                left = event.first;
            }
            count += event.second;
            //��֮��Ϊ0,��Ҫ����һ��������
            if (count == 0) {
                ans.push_back({ left, event.first - 1 });
            }
        }
        return ans;
    }
};
