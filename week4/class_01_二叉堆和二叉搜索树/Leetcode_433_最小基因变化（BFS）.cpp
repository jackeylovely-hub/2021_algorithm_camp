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
            //取队头
            string s = q.front();
            q.pop();
            //遍历所有出边
            for (int i = 0; i < 8; i++) {
                for (int j = 0; j < 4; j++) {
                    if (s[i] == gene[j]) continue;
                    string ns = s;
                    ns[i] = gene[j];
                    //如果bank里面不包含ns跳过，数组查找为O(n),建立一个哈希表
                    if (bankSet.find(ns) == bankSet.end()) continue;
                    //从s到ns的边
                    //depth里面没有包含ns
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