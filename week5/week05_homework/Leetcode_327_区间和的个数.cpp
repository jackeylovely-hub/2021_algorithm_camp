/* 解法：离散化+树状数组
    求前缀和s[]中有多少数位于[lower, upper]之间
    固定i： j<i
    lower =< s[i] - s[j] <= upper;
    结论：s[i] - upper =< s[j] <= s[i]-lower
    树状数组f[1~s[i]-lower]-f[1~s[i] - upper-1]可以求出前缀和的个数；
    时间复杂度O(nlogn)
*/
typedef long long LL;
class Solution {
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        n = nums.size();
        vector<LL> s(n + 1, 0);//前缀和爆int
        alls.push_back(0);
        for (int i = 1; i <= n; i++) {
            //求前缀和
            s[i] = s[i - 1] + nums[i - 1];
            //离散化
            alls.push_back(s[i]);
            alls.push_back(s[i] - lower);
            alls.push_back(s[i] - upper - 1);
        }
        sort(alls.begin(), alls.end());
        alls.erase(unique(alls.begin(), alls.end()), alls.end());
        //初始化树状数组（tr[i]：前缀和s[i]的个数的数量为tr[i]）
        m = alls.size();
        tr.resize(m + 1);

        int res = 0;
        //前缀和s[0]数量加1;
        add(get(s[0]), 1);
        //s[1]开始遍历，求满足条件的区间个数，一直求到s[n];
        for (int i = 1; i <= n; i++) {
            res += sum(get(s[i] - lower)) - sum(get(s[i] - upper - 1));
            add(get(s[i]), 1);
        }
        return res;
    }
private:
    //离散化(二分)找到第一个大于等于x的数
    int get(LL x) {
        int l = 0, r = alls.size() - 1;
        while (l < r) {
            int mid = (l + r) >> 1;
            if (alls[mid] >= x) r = mid;
            else               l = mid + 1;
        }
        return r + 1;//离散后下标从1开始;
    }
    //树状数组模板
    int lowbit(int x) {
        return x & -x;
    }
    int sum(int x) {
        int res = 0;
        for (int i = x; i; i -= lowbit(i))
            res += tr[i];
        return res;
    }
    void add(int x, int c) {
        for (int i = x; i <= m; i += lowbit(i))
            tr[i] += c;
    }

    vector<int> tr; //树状数组
    vector<LL> alls;//离散化数组 (爆int) 
    int n;
    int m;
};