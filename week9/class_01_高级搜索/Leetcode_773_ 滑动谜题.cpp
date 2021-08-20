/* 解法一：普通bfs解法: bfs队列中存放状态，此处的状态为2*3的矩阵，hash成整数方便存储*/
class Solution {
public:
    int slidingPuzzle(vector<vector<int>>& board) {
        int res = 123450;
        vector<int> list;
        for (int i = 0; i < 2; i++)
            for (int j = 0; j < 3; j++)
                list.push_back(board[i][j]);
        int start = zip(list);
        q.push(start);
        dist[start] = 0;
        while (!q.empty()) {
            int now = q.front();
            q.pop();
            //如何扩展->怎样将0取出
            auto a = unzip(now);
            int pos = getZeroIndex(a);
            //向左滑 向右滑 向上滑 向下滑
            if (pos != 0 && pos != 3) insert(pos, pos - 1, a, now);
            if (pos != 2 && pos != 5) insert(pos, pos + 1, a, now);
            if (pos >= 3)  insert(pos, pos - 3, a, now);
            if (pos < 3)   insert(pos, pos + 3, a, now);
            if (dist.find(res) != dist.end()) return dist[res];
        }
        return -1;
    }
private:
    void insert(int pos, int newPos, vector<int> a, int now) {
        swap(a[pos], a[newPos]);
        int next = zip(a);
        if (dist.find(next) == dist.end() || dist[next] > dist[now] + 1) {
            dist[next] = dist[now] + 1;
            q.push(next);
        }
        //因为要做四次，所以a要还原
        swap(a[pos], a[newPos]);
    }
    int getZeroIndex(vector<int>& a) {
        for (int i = 0; i < 6; i++)
            if (a[i] == 0) return i;
        return -1;
    }
    vector<int> unzip(int state) {
        vector<int> a(6, 0);
        for (int i = 5; i >= 0; i--) {
            a[i] = state % 10;
            state /= 10;
        }
        return a;
    }
    int zip(vector<int>& a) {
        int res;
        //这里的原始错误为res += a[i] * 10
        for (int i = 0; i <= 5; i++) res = res * 10 + a[i];
        return res;
    }
    queue<int> q;
    unordered_map<int, int> dist; //存放一个数值到距离的映射；
};
//解法二：A*算法
/*
    A*算法解法:
    注意估价函数的设置，
    bfs队列中存放状态，此处的状态为2*3的矩阵，hash成整数方便存储
*/
typedef pair<int, int> PII;
class Solution {
public:
    int slidingPuzzle(vector<vector<int>>& board) {
        int res = 123450;
        vector<int> list;
        for (int i = 0; i < 2; i++)
            for (int j = 0; j < 3; j++)
                list.push_back(board[i][j]);
        int start = zip(list);
        dist[start] = 0;
        q.push(make_pair(0 + evalate(list), start));
        while (!q.empty()) {
            int now = q.top().second;
            q.pop();
            //如何扩展->怎样将0取出
            auto a = unzip(now);
            if (now == res) return dist[res];
            int pos = getZeroIndex(a);
            //向左滑 向右滑 向上滑 向下滑
            if (pos != 0 && pos != 3) insert(pos, pos - 1, a, now);
            if (pos != 2 && pos != 5) insert(pos, pos + 1, a, now);
            if (pos >= 3)  insert(pos, pos - 3, a, now);
            if (pos < 3)   insert(pos, pos + 3, a, now);
        }
        return -1;
    }
private:
    //A*算法的估价函数
    int evalate(vector<int>& a) {
        int res = 0;
        for (int i = 0; i < 6; i++) {
            int x = i / 3, y = i % 3;
            int tx = (a[i] - 1) / 3, ty = (a[i] - 1) % 3;
            res += abs(x - tx) + abs(y - ty);
        }
        return res;
    }
    void insert(int pos, int newPos, vector<int> a, int now) {
        swap(a[pos], a[newPos]);
        int next = zip(a);
        if (dist.find(next) == dist.end() || dist[next] > dist[now] + 1) {
            dist[next] = dist[now] + 1;
            q.push(make_pair(dist[next] + evalate(a), next));
        }
        //因为要做四次，所以a要还原
        swap(a[pos], a[newPos]);
    }
    int getZeroIndex(vector<int>& a) {
        for (int i = 0; i < 6; i++)
            if (a[i] == 0) return i;
        return -1;
    }
    vector<int> unzip(int state) {
        vector<int> a(6, 0);
        for (int i = 5; i >= 0; i--) {
            a[i] = state % 10;
            state /= 10;
        }
        return a;
    }
    int zip(vector<int>& a) {
        int res;
        //这里的原始错误为res += a[i] * 10
        for (int i = 0; i <= 5; i++) res = res * 10 + a[i];
        return res;
    }
    //pair<int,int> 数+距离
    priority_queue<PII, vector<PII>, greater<PII>> q;
    unordered_map<int, int> dist; //存放一个数值到距离的映射；
};
