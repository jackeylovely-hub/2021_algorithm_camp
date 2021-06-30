/*
˼·���ҵ��������� x1,x2,x3...�����������ֵ��±꣬�����ϣ��
������һ�飬���³��ȣ�
*/
class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        unordered_map<int, int> h, minh, maxh;
        //�ҵ����Ķȶ�Ӧ������������ֺ������ֵ��±�
        int du = 0;
        for (int i = 0; i < nums.size(); i++) {
            int x = nums[i];
            du = max(du, ++h[x]);
            if (!minh.count(x)) minh[x] = i;
            maxh[x] = i;
        }
        //���³���
        int res = INT_MAX;
        for (auto& x : nums) {
            if (h[x] == du) {
                res = min(res, maxh[x] - minh[x] + 1);
            }
        }
        return res;
    }
};





