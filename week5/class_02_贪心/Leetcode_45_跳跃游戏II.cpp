//贪心思想：决策范围拓展
class Solution {
public:
    int jump(vector<int>& nums) {
        int ans = 0;
        int now = 0;
        //至少要往后看一步，所以走到nums.size()-2就是最后一步了
        while (now < nums.size() - 1) {
            //特判
            if (nums[now] == 0) return 0;
            int right = now + nums[now];
            //可以跳到头，直接返回
            if (right >= nums.size() - 1) return ans + 1;
            //如不可以在上一步跳到头,往后跳一步看看
            int next = now + 1;
            for (int i = now + 2; i <= right; i++) {
                int next_right = i + nums[i];
                //已知now,now+1找[now+2 ....right]之间找到下一步跳更远的
                if (next_right > next + nums[next]) next = i;
            }
            //更新这一步
            now = next;
            ans++;
        }
        return ans;
    }
};