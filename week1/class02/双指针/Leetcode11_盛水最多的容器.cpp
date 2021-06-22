//双指针
class Solution {
public:
    int maxArea(vector<int>& height) {
        int i = 0, j = height.size() - 1;
        int ans = 0;
        while (i < j) {
            //注意：先计算后移动。
            ans = max(ans, (j - i) * min(height[i], height[j]));
            if (height[i] > height[j]) j--;
            else i++;
        }
        return ans;
    }
};