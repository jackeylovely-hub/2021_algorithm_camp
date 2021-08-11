#include<iostream>
#include<algorithm>
#include<queue>
#include<cstring>

using namespace std;

const int N = 1e6 + 10;

typedef pair<int, int> PII;//最短路 节点(node y)

//邻接表存储稀疏图
int h[N], e[N], w[N], ne[N], idx;
int dist[N];
bool st[N];
int n, m;

void add(int a, int b, int c) {
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
}

int dijkstra() {
    memset(dist, 0x3f, sizeof dist);
    dist[1] = 0;

    priority_queue<PII, vector<PII>, greater<PII>> heap;
    heap.push({ 0,1 });

    while (heap.size()) {
        auto t = heap.top();
        heap.pop();
        int ver = t.second, distance = t.first;
        if (st[ver]) continue;//去掉冗余
        //标记为已访问
        st[ver] = true;
        //遍历所有的出边:注意邻接表的遍历
        for (int i = h[ver]; i != -1; i = ne[i]) {
            int j = e[i];//node y;
            if (dist[j] > distance + w[i]) {
                dist[j] = distance + w[i];
                heap.push({ dist[j], j });
            }
        }
    }
    if (dist[n] == 0x3f3f3f3f) return -1;
    return dist[n];
}
int main() {
    cin >> n >> m;
    //初始化邻接表所有表头
    memset(h, -1, sizeof h);

    while (m--) {
        int a, b, c;
        cin >> a >> b >> c;
        add(a, b, c);
    }
    cout << dijkstra() << endl;
    return 0;
}