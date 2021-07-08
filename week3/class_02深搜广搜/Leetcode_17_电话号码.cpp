class Solution {
public:
    vector<string> letterCombinations(string digits) {
        //特判。排除空的情况
        if (digits.length() == 0) return {};
        edges['2'] = "abc";
        edges['3'] = "def";
        edges['4'] = "ghi";
        edges['5'] = "jkl";
        edges['6'] = "mno";
        edges['7'] = "pqrs";
        edges['8'] = "tuv";
        edges['9'] = "wxyz";
        dfs(digits, 0);
        return ans;
    }

private:
    void dfs(string& digits, int index) {
        if (index == digits.length()) {
            ans.push_back(s);
            return;
        }
        //循环内部的变量容易出错；遍历哈希表
        for (char ch : edges[digits[index]]) {
            s.push_back(ch);
            dfs(digits, index + 1);
            s.pop_back();
        }
    }
    string s;
    unordered_map<char, string> edges;
    vector<string> ans;
};