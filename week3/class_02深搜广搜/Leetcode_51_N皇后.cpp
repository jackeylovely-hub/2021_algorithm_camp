class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        this->n = n;
        used = vector<bool>(n, false);
        dfs(0);
        vector<vector<string>> result;
        for (vector<int>& per : ans) {
            vector<string> res;
            for (int row = 0; row < n; row++) {
                string s(n, '.');
                int col = per[row];
                s[col] = 'Q';
                res.push_back(s);
            }
            result.push_back(res);
        }
        return result;
    }
private:
    void dfs(int row) {
        if (row == n) {
            // for(int x: s) {
            //     cout<< x;
            // }
            // cout << endl;
            ans.push_back(s);
            return;
        }
        for (int col = 0; col < n; col++) {
            if (!used[col] && !usedIminusJ[row - col] && !usedIplusJ[row + col]) {
                used[col] = true;
                usedIplusJ[row + col] = true;
                usedIminusJ[row - col] = true;
                s.push_back(col);
                dfs(row + 1);
                s.pop_back();
                usedIminusJ[row - col] = false;
                usedIplusJ[row + col] = false;
                used[col] = false;
            }
        }
    }

    vector<vector<int>> ans;
    vector<int> s;
    vector<bool> used;
    int n;
    unordered_map<int, bool> usedIplusJ;
    unordered_map<int, bool> usedIminusJ;
};