class NumArray {
public:
    NumArray(vector<int>& _nums) {
        nums = _nums;
        //真他妈吐了，重复写成int n 之后不报错，反而显示结果[null,0,null,0]
        n = nums.size();
        tr = vector<int>(n + 1, 0);
        for (int i = 0; i < n; i++) {
            add(i + 1, nums[i]);
        }
    }

    void update(int index, int val) {
        ;
        add(index + 1, val - nums[index]);
        nums[index] = val;
    }

    int lowbit(int x) {
        return x & (-x);
    }
    void add(int x, int c) {
        for (int i = x; i <= n; i += lowbit(i)) tr[i] += c;
    }
    int sum(int x) {
        int res = 0;
        for (int i = x; i; i -= lowbit(i)) res += tr[i];
        return res;
    }
    int sumRange(int left, int right) {
        return sum(right + 1) - sum(left);
    }
private:
    int n;
    vector<int> nums;
    vector<int> tr;
};