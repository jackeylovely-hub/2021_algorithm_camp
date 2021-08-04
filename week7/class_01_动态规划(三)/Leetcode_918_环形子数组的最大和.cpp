/*
    (1)线性子段和:
        线性数组的做法：
        for(int i = 1; i <= n; i ++ ) sum[i] = sum[i-1] + nums[i-1];
        (1)朴素：
        for i
            for j
            ans = max(ans, sum[i]-sum[j]);
        (2)分离i j:
        for i
            int temp;
            for j
                temp = min(temp, sum[j]);
            ans = max(ans, sum[i] - temp);
        (3)简化循环：
        for i
            temp = min(temp, sum[i-1]);
            ans = max(ans, sum[i] - temp);
    (2)环形数组子段和：
        做法1： 1.求线性子数组的最大子段和;
                2.头尾最大，中间最小，总和减去最小子段和
                max(1., 2.);
        做法2： 单调队列
                3 -1 2 -1 3 -1 2 -1  补成长度为2n
                滑窗的大小为n-1  ans = max(ans, sum[i] - 这个最小值);
*/
//解法一：单调队列
class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int n = nums.size();
        nums.insert(nums.begin(), nums.begin(), nums.end());
        nums.insert(nums.begin(), 0);
        vector<int> sum(2 * n + 1, 0);
        int ans = -1e9;
        deque<int> q;
        //搞一个零进去，方便形成窗口
        q.push_back(0);
        for (int i = 1; i <= 2 * n; i++) sum[i] = sum[i - 1] + nums[i];
        for (int i = 1; i <= 2 * n; i++) {
            // j1比j2优的条件 sum[j1] < sum[j2];
            //1.判断队头的合法性 上界 i-1 下界 i-n;
            while (!q.empty() && q.front() < i - n) q.pop_front();
            //2.取队头更新答案
            ans = max(ans, sum[i] - sum[q.front()]);
            //3.维护队列的单调性，确保新元素的插入
            while (!q.empty() && sum[q.back()] >= sum[i]) q.pop_back();
            q.push_back(i);
        }
        return ans;
    }
};
//解法二：
class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int n = nums.size();
        nums.insert(nums.begin(), 0); // 1 ~ n
        // 前缀和
        vector<int> sum(n + 1, 0);
        for (int i = 1; i <= n; i++) sum[i] = sum[i - 1] + nums[i];
        // 最大子段和
        int ans = -1000000000;
        int temp = sum[0];
        for (int i = 1; i <= n; i++) {
            temp = min(temp, sum[i - 1]);
            ans = max(ans, sum[i] - temp);
        }

        // 最小子段和
        int ansMin = 1000000000;
        temp = sum[0];
        for (int i = 1; i < n; i++) {
            temp = max(temp, sum[i - 1]);
            ansMin = min(ansMin, sum[i] - temp);
        }
        // 不能把1~n全扣掉（不能用sum[n]-sum[0]）
        // 最小子段和不能全取1~n，所以sum[n]只能减掉sum[1..n-1]
        temp = sum[1];
        for (int j = 2; j < n; j++) temp = max(temp, sum[j]);
        if (n > 1) ansMin = min(ansMin, sum[n] - temp);
        // 总和 - 最小子段和 = 头尾各取一段最大
        ans = max(ans, sum[n] - ansMin);
        return ans;
    }
};