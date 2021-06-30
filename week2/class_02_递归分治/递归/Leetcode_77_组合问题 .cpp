//�ⷨһ���ݹ�δ��֦
class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        this->n = n;
        this->k = k;
        dfs(1);
        return ans;
    }
    void dfs(int index) {
        if (index == n + 1) {
            if (res.size() == k) {
                ans.push_back(res);
            }
            return;
        }
        dfs(index + 1);
        res.push_back(index);
        dfs(index + 1);
        res.pop_back();
    }

private:
    vector<int> res;
    vector<vector<int>> ans;
    int n;
    int k;
};
//�ⷨ�����ݹ��֦
class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        this->n = n;
        this->k = k;
        dfs(1);
        return ans;
    }
    void dfs(int index) {
        //ѡ�����Ѿ�����k�������߰�ʣ�µ���ȫѡ��Ҳ����k��
        if (res.size() > k || res.size() + n - index + 1 < k) {
            return;
        }
        if (index == n + 1) {
            if (res.size() == k) {
                ans.push_back(res);
            }
            return;
        }
        dfs(index + 1);
        res.push_back(index);
        dfs(index + 1);
        res.pop_back();
    }
private:
    vector<int> res;
    vector<vector<int>> ans;
    int n;
    int k;
};







