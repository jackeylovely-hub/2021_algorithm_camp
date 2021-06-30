/*
* ����ʱ�临�Ӷȵķ�����
* �ַ����ĳ��ȷֱ�Ϊn1,n2,n3...
* ��һ��for��ʱ�临�Ӷȣ�
* n1lon(n1)+n2log(n2)+n3log(n3)+...
* <= n1lon(n)+n2log(n)+n3log(n)
* =(n1+n2+3+...)logn = nlog(n)
* �����ܵ�ʱ�临�Ӷ� nlog(n)+n Ϊnlog(n);
*/
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> group;
        for (auto& str : strs) {
            auto copy = str;
            sort(copy.begin(), copy.end());
            group[copy].push_back(str);
        }
        //C++ ��α�����ϣ��
        vector<vector<string>> ans;
        for (auto pr : group) {
            ans.push_back(pr.second);
        }
        return ans;
    }
};
