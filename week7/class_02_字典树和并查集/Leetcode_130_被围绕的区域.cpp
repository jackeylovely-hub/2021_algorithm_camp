class Solution {
public:
    void solve(vector<vector<char>>& board) {
        m = board.size();
        n = board[0].size();
        fa = vector<int>(m * n + 1, 0);
        //初始化并查集
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                fa[get(i, j)] = get(i, j);
        fa[m * n] = m * n;
        //
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++) {
                if (board[i][j] == 'X') continue;
                for (int k = 0; k < 4; k++) {
                    int nx = i + dx[k];
                    int ny = j + dy[k];
                    //处理边界，认为根节点为O
                    if (nx < 0 || ny < 0 || nx >= m || ny >= n) {
                        fa[find(get(i, j))] = find(n * m);
                    }
                    else if (board[nx][ny] == 'O') {
                        fa[find(get(nx, ny))] = find(get(i, j));
                    }
                }
            }
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (board[i][j] == 'O' && find(get(i, j)) != find(n * m)) {
                    board[i][j] = 'X';
                }
    }
private:
    int get(int i, int j) {
        return i * n + j;
    }
    // void unionSet(int i, int j){
    //     int x = find(i);
    //     int y = find(j);
    //     if(x != y) fa[x] = y;
    // }
    int find(int x) {
        if (x == fa[x]) return x;
        return fa[x] = find(fa[x]);
    }
    //方向数组 上 左 下 右
    int dx[4] = { 0, -1, 0, 1 };
    int dy[4] = { 1, 0, -1, 0 };
    int m;
    int n;
    vector<int> fa;
};