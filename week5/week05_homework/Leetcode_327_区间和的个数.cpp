/* �ⷨ����ɢ��+��״����
    ��ǰ׺��s[]���ж�����λ��[lower, upper]֮��
    �̶�i�� j<i
    lower =< s[i] - s[j] <= upper;
    ���ۣ�s[i] - upper =< s[j] <= s[i]-lower
    ��״����f[1~s[i]-lower]-f[1~s[i] - upper-1]�������ǰ׺�͵ĸ�����
    ʱ�临�Ӷ�O(nlogn)
*/
typedef long long LL;
class Solution {
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        n = nums.size();
        vector<LL> s(n + 1, 0);//ǰ׺�ͱ�int
        alls.push_back(0);
        for (int i = 1; i <= n; i++) {
            //��ǰ׺��
            s[i] = s[i - 1] + nums[i - 1];
            //��ɢ��
            alls.push_back(s[i]);
            alls.push_back(s[i] - lower);
            alls.push_back(s[i] - upper - 1);
        }
        sort(alls.begin(), alls.end());
        alls.erase(unique(alls.begin(), alls.end()), alls.end());
        //��ʼ����״���飨tr[i]��ǰ׺��s[i]�ĸ���������Ϊtr[i]��
        m = alls.size();
        tr.resize(m + 1);

        int res = 0;
        //ǰ׺��s[0]������1;
        add(get(s[0]), 1);
        //s[1]��ʼ���������������������������һֱ��s[n];
        for (int i = 1; i <= n; i++) {
            res += sum(get(s[i] - lower)) - sum(get(s[i] - upper - 1));
            add(get(s[i]), 1);
        }
        return res;
    }
private:
    //��ɢ��(����)�ҵ���һ�����ڵ���x����
    int get(LL x) {
        int l = 0, r = alls.size() - 1;
        while (l < r) {
            int mid = (l + r) >> 1;
            if (alls[mid] >= x) r = mid;
            else               l = mid + 1;
        }
        return r + 1;//��ɢ���±��1��ʼ;
    }
    //��״����ģ��
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

    vector<int> tr; //��״����
    vector<LL> alls;//��ɢ������ (��int) 
    int n;
    int m;
};