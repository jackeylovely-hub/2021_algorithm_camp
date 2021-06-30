/*
* 关于时间复杂度的分析：
* 字符串的长度分别为n1,n2,n3...
* 第一个for的时间复杂度：
* n1lon(n1)+n2log(n2)+n3log(n3)+...
* <= n1lon(n)+n2log(n)+n3log(n)
* =(n1+n2+3+...)logn = nlog(n)
* 所以总的时间复杂度 nlog(n)+n 为nlog(n);
*/
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> group;
        for (auto& str : strs) {
            auto copy = str;
            sort(copy.begin(), copy.end());
            group[copy].push_back(str);
        }
        //C++ 如何遍历哈希表；
        vector<vector<string>> ans;
        for (auto pr : group) {
            ans.push_back(pr.second);
        }
        return ans;
    }
};
