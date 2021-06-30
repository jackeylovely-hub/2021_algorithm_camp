//�ڳ�ʱ�ı�Ե����û�и��õ�������
class Solution {
    //��Ϊk�����������
private:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> sum(n + 1, 0);
        for (int i = 1; i <= n; i++) {
            sum[i] = sum[i - 1] + nums[i - 1];
        }
        unordered_map<int, int> h;
        h[0] = 1;
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            ans += h[sum[i] - k];
            h[sum[i]]++;
        }
        return ans;
    }
    //��άת��Ϊһά
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        int ans = 0;
        for (int i = 0; i < m; i++) {
            vector<int> sum(n);
            for (int j = i; j < m; j++) {
                for (int c = 0; c < n; c++) {
                    sum[c] += matrix[j][c];
                }
                ans += subarraySum(sum, target);
            }
        }
        return ans;
    }
};
