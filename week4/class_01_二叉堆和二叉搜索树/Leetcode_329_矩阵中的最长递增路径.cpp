//解法一：DFS+记忆化搜索
class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        this->m = matrix.size();
        this->n = matrix[0].size();
        map = vector<vector<int>>(m, vector<int>(n, -1));
        int ans = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                ans = max(ans, howfar(matrix, i, j));
            }
        }
        return ans;
    }
private:
    int howfar(vector<vector<int>>& matrix, int x, int y) {
        if (map[x][y] != -1) return map[x][y];
        //注意此处的初始化
        map[x][y] = 1;
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            //注意判断数组越界
            if (nx < 0 || ny < 0 || nx >= m || ny >= n) continue;
            //（x,y） 能走的最远距离等于（nx,ny）能走的最远距离+1；
            if (matrix[nx][ny] > matrix[x][y]) {
                map[x][y] = max(map[x][y], howfar(matrix, nx, ny) + 1);
            }
        }
        return map[x][y];
    }
    //全局变量
    int m;
    int n;
    //上  左 下 右
    int dx[4] = { 0,-1,0,1 };
    int dy[4] = { 1,0,-1,0 };
    vector<vector<int>> map;
};
//解法二：BFS
class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        m = matrix.size();
        n = matrix[0].size();
        edges = vector<vector<int>>(m * n, vector<int>());
        inDeg = vector<int>(m * n, 0);
        dist = vector<int>(m * n, 0);
        //方向数组：上 左 下 右
        const int dx[4] = { 0,-1,0,1 };
        const int dy[4] = { 1,0,-1,0 };
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                for (int k = 0; k < 4; k++) {
                    int nx = i + dx[k];
                    int ny = j + dy[k];
                    if (isValid(nx, ny) && matrix[nx][ny] > matrix[i][j]) {
                        //建立边之间的联系
                        addEdge(num(i, j), num(nx, ny));
                    }
                }
            }
        }
        topSort();
        int ans = 0;
        for (int i = 0; i < m * n; i++) {
            ans = max(ans, dist[i]);
        }
        return ans;
    }
private:
    //加边 x---y
    void addEdge(int x, int y) {
        edges[x].push_back(y);
        inDeg[y]++;
    }
    //拓扑排序
    void topSort() {
        queue<int> q;
        //加入队头
        for (int i = 0; i < m * n; i++) {
            if (inDeg[i] == 0) q.push(i), dist[i] = 1;
        }
        while (!q.empty()) {
            //取队头，pop掉
            int x = q.front();
            q.pop();
            //遍历x所有的出边y
            for (auto y : edges[x]) {
                inDeg[y]--;
                //计算距离 ：上一步加一
                dist[y] = max(dist[y], dist[x] + 1);
                if (inDeg[y] == 0) {
                    q.push(y);
                }
            }
        }
    }
    bool isValid(int x, int y) {
        //注意m代表行，n代表列
        return x >= 0 && x < m&& y >= 0 && y < n;
    }
    //二维映射成一维
    int num(int i, int j) {
        return i * n + j;
    }

    int m;
    int n;
    vector<vector<int>> edges;
    vector<int> inDeg;
    vector<int> dist;
};