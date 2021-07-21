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
                //返回最大票数
                maxc = sum[p];
                //最大票数对应的人
                maxp = p;
            }
            //更新wins数组
            wins[i] = maxp;
        }
    }
    //二分：找到大于t的最小的数；
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