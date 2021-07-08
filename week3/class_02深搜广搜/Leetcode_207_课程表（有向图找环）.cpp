//有向图找环
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        n = numCourses;
        edges = vector<vector<int>>(n, vector<int>());
        inDeg = vector<int>(n, 0);
        //加边
        for (vector<int>& pre : prerequisites) {
            int ai = pre[0];
            int bi = pre[1];
            addEdge(bi, ai);
        }
        return topSort() == n;
    }

private:
    int topSort() {
        //注意变量的初始化
        int learned = 0;
        //BFS需要队列结构
        queue<int> q;
        //找到入度为0的点加入队列
        for (int i = 0; i < n; i++)
            if (inDeg[i] == 0)
                q.push(i);
        while (!q.empty()) {
            int x = q.front();
            q.pop();
            //每个点只入队出队一次，可以看访问了多少节点
            learned++;
            //遍历所有的出边，度减为0时入队
            for (int y : edges[x]) {
                inDeg[y]--;
                if (inDeg[y] == 0) {
                    q.push(y);
                }
            }
        }
        return learned;
    }

    void addEdge(int x, int y) {
        edges[x].push_back(y);
        //入度数
        inDeg[y]++;
    }

    int n;
    //出边数组：记录节点0-n的所有出边。n*n;
    vector<vector<int>> edges;
    //入度数数组
    vector<int> inDeg;
};