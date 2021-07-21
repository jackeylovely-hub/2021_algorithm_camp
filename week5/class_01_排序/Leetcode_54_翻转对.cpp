//归并模型： i < j 且 nums[i] > 2*nums[j] 条件矛盾
//所有在左边的二元组+所有在右边的二元组+ i在左，j在右;
class Solution {
public:
    int reversePairs(vector<int>& nums) {
        ans = 0;
        mergeSort(nums, 0, nums.size() - 1);
        return ans;
    }
private:
    void mergeSort(vector<int>& nums, int left, int right) {
        if (left >= right) return;

        int mid = left + (right - left) / 2;
        mergeSort(nums, left, mid);
        mergeSort(nums, mid + 1, right);
        calculate(nums, left, mid, right);
        merge(nums, left, mid, right);
    }

    void merge(vector<int>& nums, int left, int mid, int right) {
        vector<int> tmp(right - left + 1);
        int i = left, j = mid + 1, k = 0;

        while (i <= mid && j <= right) {
            if (nums[i] <= nums[j]) tmp[k++] = nums[i++];
            else {
                tmp[k++] = nums[j++];
            }
        }
        while (i <= mid) tmp[k++] = nums[i++];
        while (j <= right) tmp[k++] = nums[j++];

        for (i = left, k = 0; i <= right;) nums[i++] = tmp[k++];
    }
    void calculate(vector<int>& nums, int left, int mid, int right) {
        for (int i = left, j = mid; i <= mid; i++) {
            while (j < right && nums[i] > 2L * nums[j + 1]) j++;
            ans += j - mid;
        }
    }
    int ans;
};