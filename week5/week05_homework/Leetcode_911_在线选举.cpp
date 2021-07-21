class TopVotedCandidate {
public:
    vector<int> wins;
    vector<int> times;
    TopVotedCandidate(vector<int>& persons, vector<int>& _times) {
        times = _times;
        int n = persons.size();
        wins.resize(n);
        vector<int> sum(n + 1);
        int maxc = 0, maxp;
        for (int i = 0; i < n; i++) {
            int p = persons[i];
            if (++sum[p] >= maxc) {
                //�������Ʊ��
                maxc = sum[p];
                //���Ʊ����Ӧ����
                maxp = p;
            }
            //����wins����
            wins[i] = maxp;
        }
    }
    //���֣��ҵ�����t����С������
    int q(int t) {
        int k = upper_bound(times.begin(), times.end(), t) - times.begin() - 1;
        return wins[k];
    }
};

/**
 * Your TopVotedCandidate object will be instantiated and called as such:
 * TopVotedCandidate* obj = new TopVotedCandidate(persons, times);
 * int param_1 = obj->q(t);
 */