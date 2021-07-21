//ʱ�临�Ӷȣ�n+n/2+n/4+... = n(1+1/2+1/3+....) <= 2n;   O(n)
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        return quick_sort(nums, 0, nums.size() - 1, nums.size() - k + 1);
    }
private:
    //���kС_ģ��;
    int quick_sort(vector<int>& nums, int l, int r, int k) {
        //�ݹ���ֹ����
        if (l == r) return nums[l];
        int i = l - 1, j = r + 1, x = nums[(l + r) >> 1];
        while (i < j) {
            while (nums[++i] < x);
            while (nums[--j] > x);
            if (i < j) swap(nums[i], nums[j]);
        }
        //������ֵĸ���
        int sl = j - l + 1;
        //���kС����ߣ��ݹ����
        if (k <= sl) return quick_sort(nums, l, j, k);
        //���k������ߣ��ݹ��ұ�
        return quick_sort(nums, j + 1, r, k - sl);
    }
};