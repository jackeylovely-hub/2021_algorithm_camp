//����һ������
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        this->m = grid.size();
        this->n = grid[0].size();
        visit = vector<vector<bool>>(m, vector<bool>(n, false));
        int ans = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '1' && !visit[i][j]) {
                    dfs(grid, i, j);
                    ans++;
                }
            }
        }
        return ans;
    }

private:
    void dfs(vector<vector<char>>& grid, int x, int y) {
        //����ѷ���
        visit[x][y] = true;
        //�������г���
        for (int i = 0; i < 4; i++) {
            //��������֮ǰ��Ҫ�ж��Ƿ�Խ��
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || ny < 0 || nx >= m || ny >= n) continue;
            if (grid[nx][ny] == '1' && !visit[nx][ny]) {
                dfs(grid, nx, ny);
            }
        }
    }

    int n;
    int m;
    vector<vector<bool>> visit;
    //N��E S W
    const int dx[4] = { 0,1,0,-1 };
    const int dy[4] = { 1,0,-1,0 };
};
//������������
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        this->m = grid.size();
        this->n = grid[0].size();
        visit = vector<vector<bool>>(m, vector<bool>(n, false));
        int ans = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '1' && !visit[i][j]) {
                    bfs(grid, i, j);
                    ans++;
                }
            }
        }
        return ans;
    }

private:
    void bfs(vector<vector<char>>& grid, int sx, int sy) {
        queue<pair<int, int>> q;
        q.push(make_pair(sx, sy));
        //����ѷ���
        visit[sx][sy] = true;
        //�������г���
        while (!q.empty()) {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            for (int i = 0; i < 4; i++) {
                //��������֮ǰ��Ҫ�ж��Ƿ�Խ��
                int nx = x + dx[i];
                int ny = y + dy[i];
                if (nx < 0 || ny < 0 || nx >= m || ny >= n) {
                    continue;
                }
                if (grid[nx][ny] == '1' && !visit[nx][ny]) {
                    q.push(make_pair(nx, ny));
                    visit[nx][ny] = true;
                }
            }
        }
    }

    int n;
    int m;
    vector<vector<bool>> visit;
    //N��E S W
    const int dx[4] = { 0,1,0,-1 };
    const int dy[4] = { 1,0,-1,0 };
};