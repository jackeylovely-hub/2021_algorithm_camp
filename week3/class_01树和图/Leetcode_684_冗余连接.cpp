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
        //�ӱ�
        for (int[] edge : input) {
            int u = edge[0];
            int v = edge[1];
            addEdges(u, v);
            addEdges(v, u);
            //ÿ��һ���ߣ�������û�л�
            for (int i = 0; i <= n; i++) visit[i] = false;
            dfs(u, -1);
            if (hasCycle) return edge;
        }
        return null;
    }
    //ͼ��������ȱ���
    //visit��������ظ�����
    private void dfs(int x, int fa) {
        //�ȱ���ѷ���
        visit[x] = true;
        //�������г���
        for (Integer y : edges.get(x)) {
            if (y == fa) continue;
            if (visit[y])  hasCycle = true;
            else dfs(y, x);
        }
    }
    private void addEdges(int x, int y) {
        edges.get(x).add(y);
    }

    //��������
    int n;
    boolean hasCycle;
    private List<List<Integer>> edges;
    private boolean[] visit;
}