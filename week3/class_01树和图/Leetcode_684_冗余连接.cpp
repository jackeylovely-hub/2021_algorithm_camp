class Solution {
    public int[] findRedundantConnection(int[][] input) {
        // [[],[],...,[]];
        n = 0;
        for (int[] edge : input) {
            int u = edge[0];
            int v = edge[1];
            n = Math.max(n, u);
            n = Math.max(n, v);
        }
        visit = new boolean[n + 1];
        edges = new ArrayList<List<Integer>>();
        for (int i = 0; i <= n; i++) {
            edges.add(new ArrayList<Integer>());
            visit[i] = false;
        }
        hasCycle = false;
        //加边
        for (int[] edge : input) {
            int u = edge[0];
            int v = edge[1];
            addEdges(u, v);
            addEdges(v, u);
            //每加一条边，看下有没有环
            for (int i = 0; i <= n; i++) visit[i] = false;
            dfs(u, -1);
            if (hasCycle) return edge;
        }
        return null;
    }
    //图的深度优先遍历
    //visit数组避免重复访问
    private void dfs(int x, int fa) {
        //先标记已访问
        visit[x] = true;
        //遍历所有出边
        for (Integer y : edges.get(x)) {
            if (y == fa) continue;
            if (visit[y])  hasCycle = true;
            else dfs(y, x);
        }
    }
    private void addEdges(int x, int y) {
        edges.get(x).add(y);
    }

    //出边数组
    int n;
    boolean hasCycle;
    private List<List<Integer>> edges;
    private boolean[] visit;
}