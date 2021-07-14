class Solution {
public:
    int findMin(vector<int>& nums) {
        //[3,4,5 ||  1,2]   
        //找第一个<=nums[right]的数
        int left = 0, right = nums.size() - 1;
        while (left < right) {
            int mid = left + right >> 1;
            if (nums[mid] <= nums[right]) right = mid;
            else                         left = mid + 1;
        }
        return nums[left];
    }
};