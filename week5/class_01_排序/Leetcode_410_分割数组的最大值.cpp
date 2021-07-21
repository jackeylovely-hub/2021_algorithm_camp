//���ִ𰸣���������Ż�����ת��Ϊ�жϽ��Ƿ����
//��С����m��������ĺ͵����ֵ��
//�ж��Ƿ���ڡ�m��������ĺ͵����ֵ��<=T;
//�ܷ�nums�ֳ�m�������������飬ʹ���Ժ͵����ֵ=T  ֻ��18 23 24 25 �Ϸ�
//�ܷ�nums�ֳ�m�������������飬ʹ���Ժ͵����ֵ<=T  17֮ǰ���Ϸ���18֮��Ϸ�������������
class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        int left = 0;
        int right = 0;
        for (int i = 0; i < nums.size(); i++) {
            left = max(left, nums[i]);
            right += nums[i];
        }
        while (left < right) {
            int mid = (left + right) >> 1;
            //���ҵ�һ��ʹ��check == true�ĵ㣻
            if (check(nums, m, mid)) right = mid;
            else           left = mid + 1;
        }
        return right;
    }
private:
    bool check(vector<int>& nums, int m, int T) {
        int subSum = 0;
        int subGroup = 1;
        for (int i = 0; i < nums.size(); i++) {
            if (subSum + nums[i] <= T) {
                subSum += nums[i];
            }
            else {
                subSum = nums[i];
                subGroup++;
            }
        }
        return subGroup <= m;
    }
};