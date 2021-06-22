/*
      ��������ģ���⣺
                ��1��˼ά��·����������ά��һ����ѡ���ϣ���ͷ�ȽϾɣ���β�Ƚ��£�ʱ�䵥���ԣ�
                                              ��ѡ���ϵ�ĳ������Ҳ���е�����
                                              ȷ�������ݼ��ķ���������j1<j2��д��j1��j2�ŵ�������nums[j1]>nums[j2];���ݼ�����ͷ���ţ���
                            �ų����ࣺ��j1��j2�j1���������ڻ���j2�̣���j1�������ࡣ
                ��2��������·��
                                            for(ÿ��Ԫ��){
                                                [1]while(��ͷ����)  ��ͷ����
                                                [2]while(��β����Ԫ�ز����㵥����) ��β����
                                                     �����µ�Ԫ��
                                                [3] ȡ��ͷ��Ϊ��Ѵ𰸡�
                                            }
                                       ע��[1][2]��Ҫ�пգ�[2][3]����ȡ����i�Ƿ�Ϊ��ѡ�

*/
//�ⷨһ������deque˫�˶���
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        deque<int> q;
        for (int i = 0; i < nums.size(); i++) {
            //��֤��ͷ�ĺϷ���
            while (!q.empty() && q.front() <= i - k) q.pop_front();
            //ά����β�ĵ����ԣ������µ�ѡ��
            while (!q.empty() && nums[q.back()] <= nums[i]) q.pop_back();
            q.push_back(i);
            //ȡ��ͷ��Ϊ��Ѵ�
            if (i >= k - 1) ans.push_back(nums[q.front()]);
        }
        return ans;
    }
};
//�ⷨ������������ģ�����
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        int q[nums.size()];
        int hh = 0, tt = -1;
        for (int i = 0; i < nums.size(); i++) {
            while (hh <= tt && q[hh] <= i - k) hh++;

            while (hh <= tt && nums[q[tt]] <= nums[i]) tt--;
            q[++tt] = i;
            if (i >= k - 1) ans.push_back(nums[q[hh]]);
        }
        return ans;
    }
};