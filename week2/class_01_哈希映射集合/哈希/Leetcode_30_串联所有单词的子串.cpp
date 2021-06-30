//�ⷨһ��һλһλ���ƶ��Ƚ�map
class Solution {
public:
    unordered_map<string, int> wordMap;
    vector<int> findSubstring(string s, vector<string>& words) {
        int tot = words.size() * words[0].length();
        wordMap = getWords(words);
        vector<int> ans;
        //������Ҫע��Ⱥ�Ҫȡ��  start + tot -1�������һ���Ӵ��ĳ��ȣ�start + tot -1  ~ [.... , s.length()-1]
        //���ԣ�start + tot ~ [.... , s.length()];
        for (int start = 0; start + tot <= s.length(); start++) {
            if (isSame(s.substr(start, tot), words)) {
                ans.push_back(start);
            }
        }
        return ans;
    }
private:
    //�ж��Ӵ���map�Ƿ��뵥�ʴ�һ��
    bool isSame(string t, vector<string>& words) {
        int m = words[0].length();
        unordered_map<string, int> subMap;
        for (int i = 0; i < t.length(); i += m) {
            subMap[t.substr(i, m)]++;
        }
        return strEqual(subMap, wordMap);
    }
    //�ж��Ӵ��е��ʳ��ֵĴ����Ƿ���words��һ����
    bool strEqual(unordered_map<string, int>& a, unordered_map<string, int>& b) {
        if (a.size() != b.size()) return false;
        for (auto& pr : a) {
            auto& key = pr.first;
            auto& value = pr.second;
            if (b.find(key) == b.end() || value != b[key]) {
                return false;
            }
        }
        return true;
    }
    //���words����ĵ���map;
    unordered_map<string, int> getWords(vector<string>& words) {
        for (auto& word : words) {
            wordMap[word] ++;
        }
        return wordMap;
    }
};
//�ⷨ����












