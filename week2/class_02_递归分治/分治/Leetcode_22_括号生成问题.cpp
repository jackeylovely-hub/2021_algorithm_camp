//最优解：分治+记忆化搜索
/*
划分子问题的标准：把第一个子问题作为不可分割的整体
划分子问题：(a)b;
(a): k个子问题
  b: n-k个子问题
*/
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        if (n == 0) return { "" };
        if (h.find(n) != h.end()) return h[n];
        vector<string> result;//注意此变量放在里面定义
        for (int k = 1; k <= n; k++) {
            vector<string> result_a = generateParenthesis(k - 1);
            vector<string> result_b = generateParenthesis(n - k);
            for (string& a : result_a) {
                for (string& b : result_b) {
                    result.push_back("(" + a + ")" + b);
                }
            }
        }
        h[n] = result;
        return result;
    }
private:
    unordered_map<int, vector<string>> h;
};
//解法二：分治
/*
划分子问题：(a)b;
(a): k个子问题
  b: n-k个子问题
*/
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        if (n == 0) return { "" };
        vector<string> ans;//注意此变量放在里面定义
        for (int k = 1; k <= n; k++) {
            vector<string> result_a = generateParenthesis(k - 1);
            vector<string> result_b = generateParenthesis(n - k);
            for (string& a : result_a) {
                for (string& b : result_b) {
                    ans.push_back("(" + a + ")" + b);
                }
            }
        }
        return ans;
    }
};





