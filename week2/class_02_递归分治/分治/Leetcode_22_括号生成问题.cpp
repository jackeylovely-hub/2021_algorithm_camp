//���Ž⣺����+���仯����
/*
����������ı�׼���ѵ�һ����������Ϊ���ɷָ������
���������⣺(a)b;
(a): k��������
  b: n-k��������
*/
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        if (n == 0) return { "" };
        if (h.find(n) != h.end()) return h[n];
        vector<string> result;//ע��˱����������涨��
        for (int k = 1; k <= n; k++) {
            vector<string> result_a = generateParenthesis(k - 1);
            vector<string> result_b = generateParenthesis(n - k);
            for (string& a : result_a) {
                for (string& b : result_b) {
                    result.push_back("(" + a + ")" + b);
                }
            }
        }
        h[n] = result;
        return result;
    }
private:
    unordered_map<int, vector<string>> h;
};
//�ⷨ��������
/*
���������⣺(a)b;
(a): k��������
  b: n-k��������
*/
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        if (n == 0) return { "" };
        vector<string> ans;//ע��˱����������涨��
        for (int k = 1; k <= n; k++) {
            vector<string> result_a = generateParenthesis(k - 1);
            vector<string> result_b = generateParenthesis(n - k);
            for (string& a : result_a) {
                for (string& b : result_b) {
                    ans.push_back("(" + a + ")" + b);
                }
            }
        }
        return ans;
    }
};





