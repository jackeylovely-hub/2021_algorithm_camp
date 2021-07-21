class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        //如果你想要arr1.size()这么大的capacity（空间），请用reserve函数（读文档 这是高级优化内容了）
        //你要的是n capacity 不是n size
        vector<int> ans;
        //必须定义count数组的大小；
        vector<int> count(1001);
        //统计字符arr1中出现的次数
        for (int i = 0; i < arr1.size(); i++) {
            count[arr1[i]]++;
        }
        for (int i = 0; i < arr2.size(); i++) {
            while (count[arr2[i]] > 0) {
                count[arr2[i]]--;
                ans.push_back(arr2[i]);
            }
        }
        //剩余在arr2中没有出现的数字，放进ans
        for (int val = 0; val <= 1000; val++) {
            while (count[val] > 0) {
                count[val]--;
                ans.push_back(val);
            }
        }
        return ans;
    }
};