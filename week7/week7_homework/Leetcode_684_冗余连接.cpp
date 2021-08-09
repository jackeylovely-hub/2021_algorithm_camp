/* 使用并查集的方法计算：无向图找环*/
class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        fa.resize(n + 1);
        //建立并查集
        for (int i = 0; i <= n; i++)
            fa[i] = i;
        for (auto& edge : edges) {
            //不在同一个集合中就合并
            int x = find(edge[0]);
            int y = find(edge[1]);
            if (x != y) fa[x] = y;
            //已经在同一个集合中，则此边导致环的出现
            else return edge;
        }
        return {};
    }
private:
    //并查集，路径压缩
    int find(int x) {
        if (x == fa[x]) return x;
        return fa[x] = find(fa[x]);
    }
    vector<int> fa;
};