//�ⷨһ��DFS+���仯����
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
        //ע��˴��ĳ�ʼ��
        map[x][y] = 1;
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            //ע���ж�����Խ��
            if (nx < 0 || ny < 0 || nx >= m || ny >= n) continue;
            //��x,y�� ���ߵ���Զ������ڣ�nx,ny�����ߵ���Զ����+1��
            if (matrix[nx][ny] > matrix[x][y]) {
                map[x][y] = max(map[x][y], howfar(matrix, nx, ny) + 1);
            }
        }
        return map[x][y];
    }
    //ȫ�ֱ���
    int m;
    int n;
    //��  �� �� ��
    int dx[4] = { 0,-1,0,1 };
    int dy[4] = { 1,0,-1,0 };
    vector<vector<int>> map;
};
//�ⷨ����BFS
class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        m = matrix.size();
        n = matrix[0].size();
        edges = vector<vector<int>>(m * n, vector<int>());
        inDeg = vector<int>(m * n, 0);
        dist = vector<int>(m * n, 0);
        //�������飺�� �� �� ��
        const int dx[4] = { 0,-1,0,1 };
        const int dy[4] = { 1,0,-1,0 };
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                for (int k = 0; k < 4; k++) {
                    int nx = i + dx[k];
                    int ny = j + dy[k];
                    if (isValid(nx, ny) && matrix[nx][ny] > matrix[i][j]) {
                        //������֮�����ϵ
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
    //�ӱ� x---y
    void addEdge(int x, int y) {
        edges[x].push_back(y);
        inDeg[y]++;
    }
    //��������
    void topSort() {
        queue<int> q;
        //�����ͷ
        for (int i = 0; i < m * n; i++) {
            if (inDeg[i] == 0) q.push(i), dist[i] = 1;
        }
        while (!q.empty()) {
            //ȡ��ͷ��pop��
            int x = q.front();
            q.pop();
            //����x���еĳ���y
            for (auto y : edges[x]) {
                inDeg[y]--;
                //������� ����һ����һ
                dist[y] = max(dist[y], dist[x] + 1);
                if (inDeg[y] == 0) {
                    q.push(y);
                }
            }
        }
    }
    bool isValid(int x, int y) {
        //ע��m�����У�n������
        return x >= 0 && x < m&& y >= 0 && y < n;
    }
    //��άӳ���һά
    int num(int i, int j) {
        return i * n + j;
    }

    int m;
    int n;
    vector<vector<int>> edges;
    vector<int> inDeg;
    vector<int> dist;
};