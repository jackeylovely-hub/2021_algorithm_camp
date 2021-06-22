//解法一：貌似超时；
class NumMatrix {
public:
    NumMatrix(vector<vector<int>>& matrix) {
        sum.clear();
        for (int i = 0; i < matrix.size(); i++) {
            sum.push_back({});
            for (int j = 0; j < matrix[i].size(); j++)
                sum[i].push_back(get_sum(i - 1, j) + get_sum(i, j - 1) - get_sum(i - 1, j - 1) + matrix[i][j]);
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        return get_sum(row2, col2) - get_sum(row1 - 1, col2) - get_sum(row2, col1 - 1) + get_sum(row1 - 1, col1 - 1);
    }

private:
    int get_sum(int i, int j) {
        if (i >= 0 && j >= 0) return sum[i][j];
        return 0;
    }

    vector<vector<int>> sum;
};

//解法二：会通过，有时也会超时
class NumMatrix {
public:
    vector<vector<int>> sum;
    NumMatrix(vector<vector<int>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return;
        int n = matrix.size(), m = matrix[0].size();
        sum = vector<vector<int>>(n + 1, vector<int>(m + 1, 0));
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                sum[i][j] = sum[i][j - 1] + sum[i - 1][j] - sum[i - 1][j - 1] + matrix[i - 1][j - 1];
            }
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        return sum[row2 + 1][col2 + 1] - sum[row1][col2 + 1] - sum[row2 + 1][col1] + sum[row1][col1];
    }
};