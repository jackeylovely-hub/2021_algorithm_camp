/*任意两点之间的最短路 floyd算法*/
class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> d = vector<vector<int>>(n, vector<int>(n));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++)
                d[i][j] = 1e9;
            d[i][i] = 0;
        }
        for (auto& edge : edges) {
            int x = edge[0], y = edge[1], z = edge[2];
            d[x][y] = z;
            d[y][x] = z;
        }
        //floyd算法
        for (int k = 0; k < n; k++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
                }
            }
        }
        //统计答案
        int ansCount = n;
        int ans = 0;
        for (int i = 0; i < n; i++) {
            int count = 0;
            for (int j = 0; j < n; j++) {
                if (i != j && d[i][j] <= distanceThreshold) count++;
            }
            if (count <= ansCount) {
                ansCount = count;
                ans = i;
            }
        }
        return ans;
    }
};