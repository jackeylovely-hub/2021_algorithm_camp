class Solution {
public:
    vector<string> subdomainVisits(vector<string>& cpdomains) {
        unordered_map<string, int> h;
        for (auto& cpdomain : cpdomains) {
            //按照空格分割
            int k = cpdomain.find(" ");
            int value = stoi(cpdomain.substr(0, k));//取子串函数
            cpdomain = cpdomain.substr(k + 1);
            //按照"."后缀分割字符串
            while (true) {
                h[cpdomain] += value;
                k = cpdomain.find(".");
                if (k == -1) break;
                cpdomain = cpdomain.substr(k + 1);
            }
        }
        //遍历哈希表
        vector<string> res;
        for (auto& pr : h) {
            res.push_back(to_string(pr.second) + " " + pr.first);
        }
        return res;
    }
};





