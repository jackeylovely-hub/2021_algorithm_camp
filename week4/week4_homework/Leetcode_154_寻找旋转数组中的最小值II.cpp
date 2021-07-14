class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;
        //É¾µôÏàËÆµÄÊı
        while (left < right && nums[left] == nums[right]) right--;
        if (nums[left] <= nums[right]) return nums[left];
        while (left < right) {
            int mid = left + right >> 1;
            if (nums[mid] <= nums[right]) right = mid;
            else                         left = mid + 1;
        }
        return nums[left];
    }
};