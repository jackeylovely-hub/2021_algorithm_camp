class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        //�������Ҫarr1.size()��ô���capacity���ռ䣩������reserve���������ĵ� ���Ǹ߼��Ż������ˣ�
        //��Ҫ����n capacity ����n size
        vector<int> ans;
        //���붨��count����Ĵ�С��
        vector<int> count(1001);
        //ͳ���ַ�arr1�г��ֵĴ���
        for (int i = 0; i < arr1.size(); i++) {
            count[arr1[i]]++;
        }
        for (int i = 0; i < arr2.size(); i++) {
            while (count[arr2[i]] > 0) {
                count[arr2[i]]--;
                ans.push_back(arr2[i]);
            }
        }
        //ʣ����arr2��û�г��ֵ����֣��Ž�ans
        for (int val = 0; val <= 1000; val++) {
            while (count[val] > 0) {
                count[val]--;
                ans.push_back(val);
            }
        }
        return ans;
    }
};