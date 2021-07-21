//时间复杂度：n+n/2+n/4+... = n(1+1/2+1/3+....) <= 2n;   O(n)
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        return quick_sort(nums, 0, nums.size() - 1, nums.size() - k + 1);
    }
private:
    //求第k小_模板;
    int quick_sort(vector<int>& nums, int l, int r, int k) {
        //递归终止条件
        if (l == r) return nums[l];
        int i = l - 1, j = r + 1, x = nums[(l + r) >> 1];
        while (i < j) {
            while (nums[++i] < x);
            while (nums[--j] > x);
            if (i < j) swap(nums[i], nums[j]);
        }
        //左边数字的个数
        int sl = j - l + 1;
        //如果k小于左边，递归左边
        if (k <= sl) return quick_sort(nums, l, j, k);
        //如果k大于左边，递归右边
        return quick_sort(nums, j + 1, r, k - sl);
    }
};