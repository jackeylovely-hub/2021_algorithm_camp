//贪心思想：
//决策的包容性：一块饼干总是要给一个孩子，满足大孩子，未来决策包含了
//满足小孩子的可能性
class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int j = 0, ans = 0;
        for (int i = 0; i < g.size(); i++) {
            while (j < s.size() && s[j] < g[i]) j++;
            if (j < s.size()) ans++, j++;
        }
        return ans;
    }
};