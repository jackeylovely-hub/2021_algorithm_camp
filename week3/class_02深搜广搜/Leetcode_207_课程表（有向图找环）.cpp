//����ͼ�һ�
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        n = numCourses;
        edges = vector<vector<int>>(n, vector<int>());
        inDeg = vector<int>(n, 0);
        //�ӱ�
        for (vector<int>& pre : prerequisites) {
            int ai = pre[0];
            int bi = pre[1];
            addEdge(bi, ai);
        }
        return topSort() == n;
    }

private:
    int topSort() {
        //ע������ĳ�ʼ��
        int learned = 0;
        //BFS��Ҫ���нṹ
        queue<int> q;
        //�ҵ����Ϊ0�ĵ�������
        for (int i = 0; i < n; i++)
            if (inDeg[i] == 0)
                q.push(i);
        while (!q.empty()) {
            int x = q.front();
            q.pop();
            //ÿ����ֻ��ӳ���һ�Σ����Կ������˶��ٽڵ�
            learned++;
            //�������еĳ��ߣ��ȼ�Ϊ0ʱ���
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
        //�����
        inDeg[y]++;
    }

    int n;
    //�������飺��¼�ڵ�0-n�����г��ߡ�n*n;
    vector<vector<int>> edges;
    //���������
    vector<int> inDeg;
};