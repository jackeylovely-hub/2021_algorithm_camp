/*
      单调队列模板题：
                （1）思维套路：单调队列维护一个候选集合，队头比较旧，队尾比较新（时间单调性）
                                              候选集合的某个属性也具有单调性
                                              确定递增递减的方法——若j1<j2，写出j1比j2优的条件，nums[j1]>nums[j2];！递减（队头最优）！
                            排除冗余：若j1比j2差，j1的生命周期还比j2短，则j1便是冗余。
                （2）代码套路：
                                            for(每个元素){
                                                [1]while(队头过期)  队头出列
                                                [2]while(队尾与新元素不满足单调性) 队尾出列
                                                     插入新的元素
                                                [3] 取队头作为最佳答案。
                                            }
                                       注：[1][2]需要判空，[2][3]步骤取决于i是否为候选项。

*/
//解法一：采用deque双端队列
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        deque<int> q;
        for (int i = 0; i < nums.size(); i++) {
            //保证队头的合法性
            while (!q.empty() && q.front() <= i - k) q.pop_front();
            //维护队尾的单调性，插入新的选项
            while (!q.empty() && nums[q.back()] <= nums[i]) q.pop_back();
            q.push_back(i);
            //取队头作为最佳答案
            if (i >= k - 1) ans.push_back(nums[q.front()]);
        }
        return ans;
    }
};
//解法二：采用数组模拟队列
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