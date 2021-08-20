//解法一：bellman-ford算法
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        //dist数组初始化，从哪里出发就将哪里置为dist[k] = 0;
        dist.resize(n + 1);
        for (int i = 1; i <= n; i++) dist[i] = 1e9;
        dist[k] = 0;
        //bellman-ford算法
        for (int round = 1; round < n; round++) {
            bool flag = false;
            for (auto& edge : times) {
                int x = edge[0];
                int y = edge[1];
                int z = edge[2];
                if (dist[x] + z < dist[y]) {
                    dist[y] = dist[x] + z;
                    flag = true;
                }
            }
            //发现没有更新退出循环
            if (!flag) break;
        }
        //根据题目求最短路中的最大值
        int ans = 0;
        for (int i = 1; i <= n; i++) ans = max(ans, dist[i]);
        //注意双==，不然结果出错，编译不报错
        if (ans == 1e9) ans = -1;
        return ans;
    }
private:
    vector<int> dist;
};
//解法二：dijkstra算法
typedef pair<int, int> PII;
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        dist.resize(n + 1);
        vector<vector<int>> ver(n + 1, vector<int>());//出边数组
        vector<vector<int>> weight(n + 1, vector<int>());//边长
        for (auto& edge : times) {
            int x = edge[0], y = edge[1], z = edge[2];
            ver[x].push_back(y);
            weight[x].push_back(z);
        }
        for (int i = 1; i <= n; i++) dist[i] = 1e9;
        dist[k] = 0;
        //dijkstra算法
        vector<bool> visit(n + 1, false);
        //最短边长，点
        priority_queue<PII, vector<PII>, greater<PII>> q;//小根堆
        q.push(make_pair(dist[k], k));
        while (!q.empty()) {
            int x = q.top().second;
            q.pop();
            if (visit[x]) continue;
            visit[x] = true;
            //遍历所有出边
            for (int i = 0; i < ver[x].size(); i++) {
                int y = ver[x][i], z = weight[x][i];
                if (dist[y] > dist[x] + z) {
                    dist[y] = dist[x] + z;
                    q.push(make_pair(dist[y], y));
                }
            }
        }
        //根据题目求最短路中的最大值
        int ans = 0;
        for (int i = 1; i <= n; i++) ans = max(ans, dist[i]);
        //注意双==，不然结果出错，编译不报错
        if (ans == 1e9) ans = -1;
        return ans;
    }
private:
    vector<int> dist;
};