class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        priority_queue<pair<int, int>> q;//�����
        for (int i = 0; i < k - 1; i++) q.push(make_pair(nums[i], i));
        for (int i = k - 1; i < nums.size(); i++) {
            q.push(make_pair(nums[i], i));
            //����ɾ�����������Ѷ���ʱ���жϣ��±��Ƿ��ڴ�������
            while (q.top().second <= i - k) q.pop();
            ans.push_back(q.top().first);
        }
        return ans;
    }
};