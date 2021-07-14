class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        unordered_set<string> bankSet;
        for (string& s : bank) bankSet.insert(s);
        const char gene[4] = { 'A','C','G','T' };
        unordered_map<string, int> depth;
        queue<string> q;
        depth[start] = 0;
        q.push(start);
        while (!q.empty()) {
            //ȡ��ͷ
            string s = q.front();
            q.pop();
            //�������г���
            for (int i = 0; i < 8; i++) {
                for (int j = 0; j < 4; j++) {
                    if (s[i] == gene[j]) continue;
                    string ns = s;
                    ns[i] = gene[j];
                    //���bank���治����ns�������������ΪO(n),����һ����ϣ��
                    if (bankSet.find(ns) == bankSet.end()) continue;
                    //��s��ns�ı�
                    //depth����û�а���ns
                    if (depth.find(ns) == depth.end()) {
                        depth[ns] = depth[s] + 1;
                        q.push(ns);
                        if (ns == end) {
                            return depth[ns];
                        }
                    }
                }
            }
        }
        return -1;
    }
};