//解法一：一位一位的移动比较map
class Solution {
public:
    unordered_map<string, int> wordMap;
    vector<int> findSubstring(string s, vector<string>& words) {
        int tot = words.size() * words[0].length();
        wordMap = getWords(words);
        vector<int> ans;
        //这里需要注意等号要取到  start + tot -1这是最后一个子串的长度：start + tot -1  ~ [.... , s.length()-1]
        //所以：start + tot ~ [.... , s.length()];
        for (int start = 0; start + tot <= s.length(); start++) {
            if (isSame(s.substr(start, tot), words)) {
                ans.push_back(start);
            }
        }
        return ans;
    }
private:
    //判断子串的map是否与单词串一样
    bool isSame(string t, vector<string>& words) {
        int m = words[0].length();
        unordered_map<string, int> subMap;
        for (int i = 0; i < t.length(); i += m) {
            subMap[t.substr(i, m)]++;
        }
        return strEqual(subMap, wordMap);
    }
    //判断子串中单词出现的次数是否与words中一样；
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
    //获得words里面的单词map;
    unordered_map<string, int> getWords(vector<string>& words) {
        for (auto& word : words) {
            wordMap[word] ++;
        }
        return wordMap;
    }
};
//解法二：












