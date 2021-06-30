/*
思路：找到度最大的数 x1,x2,x3...最早和最晚出现的下标，存入哈希表
最后遍历一遍，更新长度；
*/
class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        unordered_map<int, int> h, minh, maxh;
        //找到最大的度对应的数的最早出现和最后出现的下标
        int du = 0;
        for (int i = 0; i < nums.size(); i++) {
            int x = nums[i];
            du = max(du, ++h[x]);
            if (!minh.count(x)) minh[x] = i;
            maxh[x] = i;
        }
        //更新长度
        int res = INT_MAX;
        for (auto& x : nums) {
            if (h[x] == du) {
                res = min(res, maxh[x] - minh[x] + 1);
            }
        }
        return res;
    }
};





