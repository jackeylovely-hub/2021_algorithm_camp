class Solution {
public:
    vector<string> subdomainVisits(vector<string>& cpdomains) {
        unordered_map<string, int> h;
        for (auto& cpdomain : cpdomains) {
            //���տո�ָ�
            int k = cpdomain.find(" ");
            int value = stoi(cpdomain.substr(0, k));//ȡ�Ӵ�����
            cpdomain = cpdomain.substr(k + 1);
            //����"."��׺�ָ��ַ���
            while (true) {
                h[cpdomain] += value;
                k = cpdomain.find(".");
                if (k == -1) break;
                cpdomain = cpdomain.substr(k + 1);
            }
        }
        //������ϣ��
        vector<string> res;
        for (auto& pr : h) {
            res.push_back(to_string(pr.second) + " " + pr.first);
        }
        return res;
    }
};





